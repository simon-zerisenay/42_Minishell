/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:56:37 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/10 18:42:57 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "parsing.h"
# include "minishell.h"

// utils
int		implement_utils(t_utils *utils);
char	**ft_arrdup(char **arr);

void	free_utils(t_utils *utils);
void	init_utils(t_utils *utils, char **envp);

#endif
