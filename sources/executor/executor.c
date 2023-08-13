/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:10:31 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/29 16:40:06 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// pipe_wait: This function waits for child processes to complete execution
// when multiple pipes are used. It takes an
// array of process IDs (pid) and the number of
// processes (amount) as arguments. It iterates over the array of process
// IDs and waits for each child process to exit using waitpid.
//  After all child processes have exited, it checks the exit
// status using WIFEXITED and sets the global g_global.error_num
// to the exit status of the last child process. It returns EXIT_SUCCESS.

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	status = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	if (g_status_code != STOP_HEREDOC)
		g_status_code = exit_status;
	return (EXIT_SUCCESS);
}

// ft_fork: This function is responsible for forking a
// child process and executing the command. It takes a t_utils pointer,
// an array of
// pipe file descriptors (end), the input file descriptor (fd_in),
// and a t_cmds pointer as arguments. It first checks if the utils->reset
// flag is set and resets the static variable i if necessary.
// Then, it forks a child process using fork and assigns the process ID to
// utils->pid[i]. If the fork fails, it calls ft_error to handle the error.
//  In the child process, it calls the dup_cmd function to
// set up the necessary file descriptors and execute the command.
// Finally, it increments i and returns EXIT_SUCCESS.
int	ft_fork(t_utils *utils, int end[2], int fd_in, t_cmds *cmd)
{
	static int	i = 0;

	if (utils->reset == true)
	{
		i = 0;
		utils->reset = false;
	}
	utils->pid[i] = fork();
	if (utils->pid[i] < 0)
		ft_error(5);
	if (utils->pid[i] == 0)
		dup_cmd(cmd, utils, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}
/*
check_fd_heredoc: This function checks the file
descriptor for input redirection. It takes a t_utils pointer,
an array of pipe file descriptors (end), and a t_cmds pointer
as arguments. If the utils->heredoc flag is set,
indicating the use of a here document, it closes
the read end of the pipe (end[0]), opens the here document
file in read-only mode, and returns the file descriptor.
Otherwise, it returns end[0], which represents the
standard input file descriptor.
*/

int	check_fd_heredoc(t_utils *utils, int end[2], t_cmds *cmd)
{
	int	fd_in;

	if (utils->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}
/*
Initializes fd_in to STDIN_FILENO, representing the
standard input file descriptor. Enters a loop to
iterate over the command structures (t_cmds) in utils->cmds.
Calls the call_expander function to expand the command and redirections.
If there is a next command (utils->cmds->next), it creates
a pipe using the pipe function and assigns the file descriptors to end.
Sends the here-document if utils->heredoc flag is true.
Calls the ft_fork function to fork a child process and execute the command.
*/

int	executor(t_utils *utils)
{
	int		end[2];
	int		fd_in;
	t_cmds	*curr_cmd;

	fd_in = STDIN_FILENO;
	curr_cmd = utils->cmds;
	while (curr_cmd)
	{
		if (curr_cmd->next)
			if (pipe(end) < 0)
				return (!ft_error(4));
		send_heredoc(utils, curr_cmd);
		if (ft_fork(utils, end, fd_in, curr_cmd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		close(end[1]);
		if (curr_cmd->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(utils, end, curr_cmd);
		if (curr_cmd->next)
			curr_cmd = curr_cmd->next;
		else
			break ;
	}
	pipe_wait(utils->pid, utils->pipes);
	return (0);
}

/*
The prepare_executor function is responsible for setting
 up the executor to execute commands entered by the user.
It sets up signal handling and calls the appropriate
functions depending on whether there are pipes or not.
This function sets up the executor to execute commands
entered by the user.
It sets up the signal handling for the execution
 of commands, specifically handling the SIGQUIT
 signal (usually triggered by pressing Ctrl+).
It sets the in_cmd flag in the g_global structure
 to indicate that the minishell is currently
  executing a command.
If there are no pipes in the command, it
calls the single_cmd function to execute
the single command stored in the command list (cmdss).
If there are pipes in the command, it
allocates memory for an array of process IDs
 (pid) to track the child processes.
It calls the executor function to execute the
commands with pipes, which handles the creation
of pipes, forking child processes, and connecting
them with pipes for communication.
*/
int	prepare_executor(t_utils *utils)
{
	signal(SIGQUIT, sigquit_handler);
	g_status_code = IN_CMD;
	if (utils->pipes == 0)
		single_cmd(utils->cmds, utils);
	else
	{
		utils->pid = ft_calloc(utils->pipes + 2, sizeof(int));
		if (!utils->pid)
			return (ft_error(1));
		if (executor(utils))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
