/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:44:48 by szerisen          #+#    #+#             */
/*   Updated: 2023/08/04 21:02:10 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// accepts input from user for parsing and execution
void	minishell_loop(t_utils *utils)
{
	while (1)
	{
		utils->input = readline(READLINE_MSG);
		implement_utils(utils);
		if (!utils->input)
		{
			reset_utils(utils);
			free_utils(utils);
			printf("exit\n");
			exit(EXIT_SUCCESS);
		}
		else if (utils->input[0] == '\0')
		{
			reset_utils(utils);
			continue ;
		}
		add_history(utils->input);
		if (parse_input(utils))
			prepare_executor(utils);
		reset_utils(utils);
	}
}

// initialization of minishell
int	main(int argc, char **argv, char **envp)
{
	t_utils	utils;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	init_signals();
	init_utils(&utils, envp);
	printf("\n%s\n\n", WELCOME_MSG);
	minishell_loop(&utils);
	free_utils(&utils);
	return (0);
}
