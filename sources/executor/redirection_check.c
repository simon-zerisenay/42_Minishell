/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:01:56 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/29 15:42:52 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
The function check_append_outfile takes a t_lexer
pointer named redirections as input and checks
the type of output redirection (> or >>). If the
redirection is >> (GREAT_GREAT), it opens the file
in append mode (O_APPEND) using open. Otherwise,
it opens the file in write mode (O_TRUNC). The
function returns the file descriptor (fd)
corresponding to the opened file.
*/
int	check_append_outfile(t_redir *redir)
{
	int	fd;

	if (redir->type == APPEND)
		fd = open(redir->path,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redir->path,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}
/*
The function handle_infile takes a char pointer
named file as input and handles input file redirection.
It opens the file in read-only mode (O_RDONLY)
using open. If the file opening fails, it prints an error
message and returns EXIT_FAILURE. If the file is
successfully opened, it duplicates the file descriptor
(fd) to the standard input file descriptor (STDIN_FILENO)
using dup2. Finally, it closes the file descriptor
if it's greater than zero and returns EXIT_SUCCESS.
*/

int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: infile: No such file or directory\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

// handles opening and creating file without writing
int	handle_open(t_redir *redir)
{
	int	fd;

	fd = open(redir->path, O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

/*
The function handle_outfile takes a t_lexer pointer
named redirection as input and handles output file redirection. It calls
the check_append_outfile function to open the file
with the appropriate mode. If the file opening fails, it prints an
error message and returns EXIT_FAILURE. If the file
is successfully opened, it duplicates the file descriptor to the
standard output file descriptor (STDOUT_FILENO) using
dup2. Finally, it closes the file descriptor if it's greater
*/

int	handle_outfile(t_redir *redir)
{
	int	fd;

	fd = check_append_outfile(redir);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}
/*
This function checks for redirections
If the redirection is LESS (<), it calls the
handle_infile() function with
the file name specified in cmd->redirections->str.
 This function handles the input
file redirection by opening the
file in read-only mode, duplicating the file descriptor
to the standard input file descriptor (STDIN_FILENO)
using dup2(), and closing the file descriptor.

If the redirection is GREAT (>) or GREAT_GREAT (>>),
it calls the handle_outfile() function
with the current redirections element. This
function handles the output file redirection by
opening the file in either truncate or append mode,
duplicating the file descriptor to the standard
output file descriptor (STDOUT_FILENO) using dup2(),
 and closing the file descriptor.
if the redirection is LESS_LESS (<<), it calls the
handle_infile() function with the here document file
name specified in cmd->hd_file_name.
This function handles the here document redirection
 in a similar way to input file redirection.
*/

int	check_redirections(t_cmds *cmd)
{
	t_redir	*redir;

	redir = cmd->redirections;
	while (redir)
	{
		if (redir->type == INPUT)
		{
			if (handle_infile(redir->path))
				return (EXIT_FAILURE);
		}
		else if (redir->type == HEREDOC)
			if (handle_infile(cmd->hd_file_name))
				return (EXIT_FAILURE);
		if (check_redir_helper(redir->type, redir) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
