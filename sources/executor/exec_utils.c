/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:14 by szerisen          #+#    #+#             */
/*   Updated: 2023/08/05 17:17:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_cmd_helper(t_cmds *cmd)
{
	char	*tmp;
	char	*tmp1;

	tmp1 = ft_strtrim(cmd->command, "/");
	if (cmd->command[0] == '/')
		tmp = ft_strjoin("/", tmp1);
	else
		tmp = ft_strdup(tmp1);
	free(tmp1);
	if (!access(tmp, F_OK))
	{
		free(tmp);
		return (exec_error(cmd->command, 2));
	}
	else
	{
		free(tmp);
		return (exec_error(cmd->command, 1));
	}
}
