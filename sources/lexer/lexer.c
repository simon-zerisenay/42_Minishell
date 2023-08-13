/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:58:27 by melsahha          #+#    #+#             */
/*   Updated: 2023/07/29 16:21:13 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// frees split structure
void	free_split(t_split *split)
{
	t_word	*del;
	t_word	*ptr;

	if (!split)
		return ;
	ptr = split->first;
	while (ptr)
	{
		free(ptr->cont);
		del = ptr;
		ptr = ptr->next;
		free(del);
	}
	free(split);
}

// splits input to space-separated words
int	split_words(char *input, t_split *split)
{
	int	i;

	i = 0;
	while (input[i])
	{
		skip_space(input, &i);
		if (input[i])
		{
			if (!define_word(input, &i, split))
				return (0);
		}
	}
	return (1);
}

// splits input, checks errors, expands env,
// combines quotes, and sorts type
t_split	*split_input(char *input, t_utils *utils)
{
	t_split	*split;

	split = (t_split *)ft_calloc(1, sizeof(t_split));
	if (!split)
	{
		ft_error(1);
		return (0);
	}
	if (!split_words(input, split) || !check_split(split))
	{
		free_split(split);
		return (0);
	}
	if (!expand_env(split, utils) || !combine_quotes(split))
	{
		free_split(split);
		return (0);
	}
	sort_split(split);
	return (split);
}

// sorts the type of word
void	sort_split(t_split *split)
{
	t_word	*ptr;

	ptr = split->first;
	if (ptr && ptr->type == STR)
		ptr->type = CMD;
	while (ptr)
	{
		if (ptr->prev && ptr->type == STR && ptr->prev->type == PIPE)
			ptr->type = CMD;
		else if (ptr->prev && ptr->prev->type == REDIR)
			ptr->type = PATH;
		else if (ptr->type == STR)
			ptr->type = ARG;
		ptr = ptr->next;
	}
}
