/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:44:34 by melsahha          #+#    #+#             */
/*   Updated: 2023/08/05 17:39:03 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	p_export(t_utils *utils, t_cmds *cmds)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!cmds->args[1] || cmds->args[1][0] == '\0')
		return ;
	else
	{
		while (cmds->args[i])
		{
			if (!check_parameter(cmds->args[i])
				&& !variable_exist(utils, cmds->args[i])
				&& !invalid_identifier(cmds->args[i], 1))
			{
				tmp = add_var(utils->envp, cmds->args[i]);
				free_double_ptr((void **)utils->envp);
				utils->envp = tmp;
			}
			else if ((invalid_identifier(cmds->args[i], 1)
					|| check_parameter(cmds->args[i])))
				return ;
			i++;
		}
	}
	return ;
}

void	p_exit(t_utils *utils, t_cmds *cmds)
{
	int		exit_code;

	if (cmds->args[1] && cmds->args[2] && is_str_digit(cmds->args[1]))
		return ;
	if (!is_str_digit(cmds->args[1]))
		exit_code = 255;
	else if (!cmds->args[1])
		exit_code = 0;
	else if (is_str_digit(cmds->args[1]))
		exit_code = ft_atoi(cmds->args[1]);
	else
		exit_code = 255;
	reset_utils(utils);
	free_utils(utils);
	exit(exit_code);
}

void	p_unset(t_utils *utils, t_cmds *cmds)
{
	char	**temp;

	if (!cmds->args[1] || invalid_identifier(cmds->args[1], 0)
		|| equal_sign(cmds->args[1]) != 0)
		return ;
	temp = del_var(utils->envp, cmds->args[1]);
	free_double_ptr((void **) utils->envp);
	utils->envp = temp;
}

void	p_cd(t_utils *utils, t_cmds *cmds)
{
	int		ret;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	if (!cmds->args[1])
		ret = p_specific_path(utils, "HOME=");
	else if (ft_strncmp(cmds->args[1], "-", 1) == 0)
		ret = p_specific_path(utils, "OLDPWD=");
	else if (cmds->args[1][0] == '~')
	{
		tmp = find_path_ret("HOME=", utils);
		tmp1 = ft_substr(cmds->args[1], 1, ft_strlen(cmds->args[1]) - 1);
		tmp2 = ft_strjoin(tmp, tmp1);
		ret = chdir(tmp2);
		free(tmp);
		free(tmp1);
		free(tmp2);
	}
	else
		ret = chdir(cmds->args[1]);
	if (ret != 0)
		return ;
	change_path(utils);
	update_path_to_env(utils);
}

void	p_builtins(t_utils *utils, t_cmds *cmd)
{
	if (cmd->builtin == m_export)
		p_export(utils, cmd);
	if (cmd->builtin == m_cd)
		p_cd(utils, cmd);
	if (cmd->builtin == m_exit)
		p_exit(utils, cmd);
	if (cmd->builtin == m_unset)
		p_unset(utils, cmd);
}
