/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:12:48 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/29 16:20:57 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	variable_exist(t_utils *utils, char *str)
{
	int	i;

	i = 0;
	while (utils->envp[i])
	{
		if (ft_strncmp(utils->envp[i],
				str, equal_sign(utils->envp[i])) == 0)
		{
			free(utils->envp[i]);
			utils->envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

/*verifies that a variable is not a digit.
if it is, returns an error not valid identifier.*/
int	check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (EXIT_FAILURE);
	if (equal_sign(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (EXIT_FAILURE);
	while (str[i] != '=')
	{
		if (check_valid_identifier(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/* copies the existing environment variables (arr) and
 adding a new variable (str) at the end of the copied list */
char	**whileloop_add_var(char **env, char **rtn, char *str)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i + 1] == NULL)
		{
			rtn[i] = ft_strdup(str);
			rtn[i + 1] = ft_strdup(env[i]);
		}
		else
			rtn[i] = ft_strdup(env[i]);
		if (rtn[i] == NULL)
		{
			free_double_ptr((void **)rtn);
			return (rtn);
		}
		i++;
	}
	if (env[0] == NULL)
		rtn[0] = ft_strdup(str);
	return (rtn);
}

/*
it takes arr and adds str and return rtn which is composed of both
it allocates memory for the additional variable and return it
*/
char	**add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(i + 2, sizeof(char *));
	if (!rtn)
	{
		ft_error(1);
		return (NULL);
	}
	i = 0;
	whileloop_add_var(arr, rtn, str);
	return (rtn);
}

/* if the command export is passed without any
arguments we just return env (acts as env)
if there is a second argument it will go inside the while loop
variable exist will check if str exist in env variable */
int	m_export(t_utils *utils, t_cmds *cmds)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!cmds->args[1] || cmds->args[1][0] == '\0')
		sorted_env(utils);
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
				return (error_invalid_identifier(cmds->args[i]));
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
