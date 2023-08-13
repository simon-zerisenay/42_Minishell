/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:49:03 by melsahha          #+#    #+#             */
/*   Updated: 2023/07/29 16:20:57 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// creates new word
t_word	*new_word(char *c, int type)
{
	t_word	*word;

	word = (t_word *)ft_calloc(1, sizeof(t_word));
	if (!word)
	{
		ft_error(1);
		return (0);
	}
	word->type = type;
	word->cont = ft_strdup(c);
	return (word);
}

// pushes word to list
int	push_word(t_split *split, char *c, int type)
{
	t_word	*word;

	word = new_word(c, type);
	if (!word)
		return (0);
	word->index = split->cmds;
	word->next = 0;
	word->prev = split->last;
	if (split->cmds == 0)
		split->first = word;
	else
		split->last->next = word;
	split->last = word;
	split->cmds++;
	return (1);
}

// prints split list for visualization
void	print_split(t_split *split)
{
	t_word	*ptr;

	ptr = split->first;
	while (ptr)
	{
		printf("%i. ", ptr->index);
		printf("%s", ptr->cont);
		if (ptr->type == CMD)
			printf(" - CMD\n");
		else if (ptr->type == REDIR)
			printf(" - REDIR\n");
		else if (ptr->type == PATH)
			printf(" - PATH\n");
		else if (ptr->type == PIPE)
			printf(" - PIPE\n");
		else if (ptr->type == QUOTE)
			printf(" - QUOTE\n");
		else if (ptr->type == ARG)
			printf(" - ARG\n");
		else if (ptr->type == STR)
			printf(" - STR\n");
		ptr = ptr->next;
	}
}

char	*expand_env_quotes(t_word *word, int *i, t_utils *utils)
{
	if (word->cont[(*i)] == '\"')
	{
		(*i)++;
		while (word->cont[(*i)] && word->cont[(*i)] != '\"')
		{
			if (word->cont[(*i)] == '$')
			{
				if (word->cont[(*i) + 1] && word->cont[(*i) + 1] == '?')
					word->cont = expand_err(word->cont, i);
				else
					found_env(word->cont, i, word, utils);
				return (word->cont);
			}
			else
				(*i)++;
		}
		if (word->cont[(*i)] == '\"')
			(*i)++;
	}
	return (word->cont);
}

int	found_env_helper(t_word *word, char *old, int *i)
{
	int		j;
	int		len;
	char	*temp;

	len = 0;
	j = (*i);
	if (old[j + 1] && old[j + 1] == '$')
	{
		temp = ft_itoa(getpid());
		(*i) = (*i) + 2;
		word->cont = replace_env(old, i, temp, 1);
		(*i) = 0;
		return (-1);
	}
	while (old[++j] && !is_space(old[j]) && old[j] != '$'
		&& !check_valid_identifier(old[j]))
		len++;
	if (!len)
	{
		(*i) = (*i) + 2;
		return (-1);
	}
	return (len);
}
