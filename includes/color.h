/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:49:15 by szerisen          #+#    #+#             */
/*   Updated: 2023/07/07 15:46:46 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RESET_COLOR	"\033[0m"
# define BLACK   		"\033[30m"
# define RED     		"\033[31m"
# define LIGHT_RED		"\033[91m"
# define GREEN   		"\033[32m"
# define LIGHT_GREEN	"\033[92m"
# define YELLOW  		"\033[33m"
# define LIGHT_YELLOW	"\033[93m"
# define BLUE    		"\033[34m"
# define LIGHT_BLUE		"\033[94m"
# define MAGENTA 		"\033[35m"
# define LIGHT_MAGENTA	"\033[95m"
# define CYAN    		"\033[36m"
# define LIGHT_CYAN		"\033[96m"
# define WHITE   		"\033[37m"
# define GREY    		"\033[90m"
# define LIGHT_GREY		"\033[37m"

# define PINK		    "\e[38;5;212m"
# define BLACK_BOLD   	"\033[1;30m"
# define RED_BOLD     	"\033[1;31m"
# define GREEN_BOLD   	"\033[1;32m"
# define YELLOW_BOLD  	"\033[1;33m"
# define BLUE_BOLD    	"\033[1;34m"
# define MAGENTA_BOLD 	"\033[1;35m"
# define CYAN_BOLD    	"\033[1;36m"
# define WHITE_BOLD   	"\033[1;37m"
# define WELCOME_MSG "hello"
# define HEREDOC_MSG	"\033[1;34m> \033[0m"

# define READLINE_MSG	"\e[38;5;212mminishell\033[34m$ \033[0m"

#endif
