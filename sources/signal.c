/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:35:54 by szerisen          #+#    #+#             */
/*   Updated: 2023/08/05 17:13:37 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	event(void)
{
	return (EXIT_SUCCESS);
}

/*
sigint_handler(int sig): This function is the signal
 handler for the SIGINT signal, which is typically sent
to a process when the user presses Ctrl+C. It takes an
integer argument sig representing the signal number.
a. If the global variable g_global.in_heredoc is false,
 it means the program is not currently inside a heredoc.
In this case, it prints a newline character (\n)
to STDERR_FILENO (standard error) using ft_putstr_fd.
b. If the global variable g_global.in_cmd is true, it
means the program is inside a command. In this case, it sets
 g_global.CTRL_C to 1 to indicate that the heredoc
 should stop, replaces the current Readline line
 with an empty string using rl_replace_line, redisplays
 the prompt and line using rl_redisplay, and sets rl_done
  to 1 to exit the Readline loop.
c. If none of the above conditions are met, it means the
program is outside a heredoc and not in a command.
It calls rl_on_new_line to move the cursor to a new line,
 replaces the current Readline line with an empty
string using rl_replace_line, redisplays the prompt and
 line using rl_redisplay, and ignores the sig parameter.
*/
// handles ctl + C
void	sigint_handler(int sig)
{
	if (g_status_code != IN_HEREDOC)
		ft_putstr_fd("\n", STDERR_FILENO);
	if (g_status_code == IN_CMD)
	{
		g_status_code = CTRL_C;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;
	}
	else if (g_status_code == IN_HEREDOC)
	{
		g_status_code = STOP_HEREDOC;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;
	}
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void) sig;
}

/*
sigquit_handler(int sig): This function
is the signal handler
for the SIGQUIT signal, which is typically sent
 to a process when the user presses
 Ctrl+\ (backslash).
 It takes an integer argument sig
 representing the signal number.
a. It prints the message "Quit: "
 followed by the value
of sig to STDERR_FILENO (standard error)
 using ft_putstr_fd and ft_putnbr_fd.
b. It prints a newline character (\n)
to STDERR_FILENO using ft_putchar_fd.
*/
// ctl+backslash
void	sigquit_handler(int sig)
{
	if (g_status_code == IN_CMD)
	{
		g_status_code = CTRL_BS;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		ft_putstr_fd("Quit: ", STDERR_FILENO);
		ft_putnbr_fd(sig, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return ;
	}
}

/*
init_signals(void): This function initializes the
signal handlers for the program.

a. It sets the Readline event hook (rl_event_hook)
to the event function. The purpose and functionality of
this event hook are not provided in the given code s
nippet.
b. It sets the signal handler for the SIGINT signal
(Ctrl+C) to sigint_handler using signal.
c. It sets the signal handler for the SIGQUIT signal (
Ctrl+) to SIG_IGN, which ignores the signal and does not perform
any specific action when it is received.
*/
void	init_signals(void)
{
	rl_catch_signals = 0;
	rl_event_hook = event;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
