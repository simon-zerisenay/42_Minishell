/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:42:44 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/29 13:12:03 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// it accepts *str, and returns function pointer
// if there is no much it returns null.

int	(*builtin_arr(char *str))(t_utils *utils, t_cmds *cmds)
{
	static void	*builtins[7][2] = {
	{"echo", m_echo},
	{"cd", m_cd},
	{"pwd", m_pwd},
	{"export", m_export},
	{"unset", m_unset},
	{"env", m_env},
	{"exit", m_exit}
	};
	int			i;

	i = 0;
	while (str && i < 7)
	{
		if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0])))
			&& !ft_strncmp(builtins[i][0], str, ft_strlen(str)))
			return (builtins[i][1]);
		i++;
	}
	return (NULL);
}

int	p_specific_path(t_utils *utils, char *str)
{
	char	*tmp;
	int		ret;

	ret = -1;
	tmp = find_path_ret(str, utils);
	if (tmp)
	{
		ret = chdir(tmp);
		free(tmp);
	}
	return (ret);
}
