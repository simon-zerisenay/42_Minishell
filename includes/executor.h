/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:56:31 by szerisen          #+#    #+#             */
/*   Updated: 2023/08/05 17:13:16 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "parsing.h"
# include "minishell.h"

// check_redirections
int				check_redirections(t_cmds *cmd);
int				handle_outfile(t_redir *redir);
int				handle_open(t_redir *redir);

// executor
int				prepare_executor(t_utils *utils);
int				executor(t_utils *utils);
int				pipe_wait(int *pid, int amount);
int				exec_error(char *str, int code);

// handle_cmd
int				find_cmd(t_cmds *cmd, t_utils *utils);
void			handle_cmd(t_cmds *cmd, t_utils *utils);
void			dup_cmd(t_cmds *cmd, t_utils *utils,
					int end[2], int fd_in);
void			single_cmd(t_cmds *cmd, t_utils *utils);
int				loop_paths(t_utils *utils, t_cmds *cmd);
int				find_exec_error(char *cmd, int code);
int				is_directory(char *path);

// heredoc
int				send_heredoc(t_utils *utils, t_cmds *cmd);

//executor_utils
int				check_redir_helper(int type, t_redir *dir);

//exec_utils
int				find_cmd_helper(t_cmds *cmd);

#endif
