/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:42:56 by szerisen          #+#    #+#             */
/*   Updated: 2023/08/05 17:40:28 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*if exit is passed without any argument it returns 0
checks if the second argument (str[1]) after the
 "exit" command is a valid numeric value.
*/
void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_double_ptr((void **) str);
	exit(exit_code);
}

// This check if the exit function has more that two arguments
// free before you determine the exit_code and exit
int	m_exit(t_utils *utils, t_cmds *cmds)
{
	char	**str;

	if (utils->pipes == 0)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (cmds->args[1] && cmds->args[2] && is_str_digit(cmds->args[1]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (cmds->args[1] && !is_str_digit(cmds->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmds->args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		reset_utils(utils);
		free_utils(utils);
		exit(255);
	}
	str = ft_arrdup(cmds->args);
	reset_utils(utils);
	free_utils(utils);
	determine_exit_code(str);
	return (EXIT_SUCCESS);
}
