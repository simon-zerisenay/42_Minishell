/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:08:27 by szerisen          #+#    #+#             */
/*   Updated: 2023/08/04 20:54:38 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(t_utils *utils)
{
	char	**tmp;
	char	*var;

	if (!utils->envp)
		utils->envp = (char **) ft_calloc(2, sizeof(char *));
	if (!utils->pwd || !utils->old_pwd)
	{
		utils->pwd = getcwd(NULL, 0);
		utils->old_pwd = NULL;
		tmp = utils->envp;
		var = ft_strjoin("PWD=", utils->pwd);
		utils->envp = add_var(utils->envp, var);
		free_double_ptr((void **) tmp);
		free(var);
		var = ft_strjoin("OLDPWD=", utils->old_pwd);
		tmp = utils->envp;
		utils->envp = add_var(utils->envp, var);
		free_double_ptr((void **) tmp);
		free(var);
	}
}

/* gets hold of the present working directory
and old pwd from the copied envp (utils->envp)
*/
int	find_pwd(t_utils *utils)
{
	int	i;

	i = 0;
	utils->pwd = 0;
	utils->old_pwd = 0;
	while (utils->envp && utils->envp[i])
	{
		if (!ft_strncmp(utils->envp[i], "PWD=", 4))
			utils->pwd = ft_substr(utils->envp[i],
					4, ft_strlen(utils->envp[i]) - 4);
		else if (!ft_strncmp(utils->envp[i], "OLDPWD=", 7))
			utils->old_pwd = ft_substr(utils->envp[i],
					7, ft_strlen(utils->envp[i]) - 7);
		i++;
	}
	check_pwd(utils);
	return (1);
}

/*
This function takes a char** parameter called envp,
 which is assumed to be an array of strings containing
environment variables. It iterates through the envp
 array, similar to the previous function.
Inside the loop, it looks for the environment
 variable "PATH" and returns its corresponding value
(the part after the equals sign) using ft_substr.
 If the "PATH" environment variable is not found,
  it returns
an empty string obtained by duplicating the
 null terminator character.
Note: It assumes that ft_substr is a custom
function to extract substrings.
*/
char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

/*
This function takes a t_utils structure
 (likely containing utility variables) as a parameter.
It calls the find_path function, passing utils->envp
 as an argument, to obtain the "PATH" environment
  variable value.
The returned value is stored in path_from_envp.
It then splits path_from_envp using ':' as the
delimiter to obtain individual paths, and
stores them in utils->paths
using ft_split. After storing the paths, it frees
the memory allocated for path_from_envp.
It then iterates through each path in utils->paths.
For each path, it checks if the last character
is not a slash ('/').
If it's not a slash, it appends a slash to the
path using ft_strjoin and assigns the updated
path to utils->paths[i].
Finally, the function returns EXIT_SUCCESS,
indicating successful parsing of the environment variables.
*/
int	parse_paths(t_utils *utils)
{
	char	*path_from_envp;
	int		i;
	char	*tmp;

	path_from_envp = find_path(utils->envp);
	utils->paths = ft_split(path_from_envp, ':');
	free(path_from_envp);
	i = 0;
	while (utils->paths[i])
	{
		if (ft_strncmp(&utils->paths[i][ft_strlen(utils->paths[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(utils->paths[i], "/");
			free(utils->paths[i]);
			utils->paths[i] = tmp;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_utils(t_utils *utils, char **envp)
{
	utils->cmds = 0;
	utils->paths = 0;
	utils->pwd = 0;
	utils->old_pwd = 0;
	utils->pipes = 0;
	utils->pid = 0;
	utils->envp = 0;
	utils->reset = false;
	if (*envp != 0)
		utils->envp = ft_arrdup(envp);
	find_pwd(utils);
}
