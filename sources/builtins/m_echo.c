/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:57:03 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/10 19:21:18 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}

/*checks if the echo function has -n flag so
that it removes new line so that it sets n_options
to true so that it does add newline
counter i will start from 1 after the command if there
is no flag (i.e 1) and will start from number
greater that 1 if there is a flag
for example: 4 if there is 3 flags

// this function iterates through the string and prints it
print_lines(i, cmds->args, STDOUT_FILENO);
// if there is no flag it will add a newline.
if (n_option == false)
	ft_putchar_fd('\n', STDOUT_FILENO);
*/
int	m_echo(t_utils *utils, t_cmds *cmds)
{
	int		i;
	int		j;
	bool	n_option;

	i = 1;
	n_option = false;
	(void) utils;
	while (cmds->args[i] && cmds->args[i][0] == '-'
		&& cmds->args[i][1] == 'n')
	{
		j = 1;
		while (cmds->args[i][j] == 'n')
			j++;
		if (cmds->args[i][j] == '\0')
			n_option = true;
		else
			break ;
		i++;
	}
	print_lines(i, cmds->args, STDOUT_FILENO);
	if (n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
