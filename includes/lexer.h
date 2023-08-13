/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:14:20 by melsahha          #+#    #+#             */
/*   Updated: 2023/07/28 15:02:50 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "parsing.h"

typedef struct s_word	t_word;
typedef struct s_utils	t_utils;

typedef struct s_split
{
	int		cmds;
	t_word	*first;
	t_word	*last;
}	t_split;

typedef struct s_word
{
	char			*cont;
	int				index;
	int				type;
	struct s_word	*next;
	struct s_word	*prev;
}	t_word;

typedef enum e_word_type
{
	CMD,
	FLAG,
	REDIR,
	PATH,
	PIPE,
	QUOTE,
	ARG,
	STR,
}	t_word_type;

t_split	*split_input(char *input, t_utils *utils);
int		check_split(t_split *split);
int		push_word(t_split *split, char *c, int type);
void	free_split(t_split *split);
int		define_word(char *input, int *i, t_split *split);
void	print_split(t_split *split);
int		combine_quotes(t_split *split);
t_word	*new_word(char *c, int type);
int		expand_env(t_split *split, t_utils *utils);
void	sort_split(t_split *split);
char	*expand_env_quotes(t_word *word, int *i, t_utils *utils);
int		found_env(char *old, int *i, t_word *word, t_utils *utils);
int		found_env_helper(t_word *word, char *old, int *i);

#endif
