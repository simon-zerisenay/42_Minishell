/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:40:29 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/29 16:20:28 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "minishell.h"
# include "parsing.h"

int		parser_error(t_word *ptr);
int		invalid_token_error(char *c);
int		token_error(t_utils *utils, int code);

void	lexer_error(int error, t_utils *utils);
int		cmd_not_found(char *str);
int		export_error(char *c);
//ft_error
int		ft_error(int error);

typedef enum e_err_code
{
	ERR_SEMICOL,
	ERR_BACKSLASH,
	ERR_QUOTES,
	ERR_PIPE,
	ERR_G,
	ERR_GG,
	ERR_L,
	ERR_LL,
	ERR_NL,
}	t_err_code;

#endif
