/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:22:53 by rogiso            #+#    #+#             */
/*   Updated: 2024/11/27 18:22:53 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PIPE_H
# define MS_PIPE_H

# include <minishell.h>

/* ms_cmd.c */
t_cmd	*generate_cmd_list(t_token *token);
t_slice	*generate_cmd_argv(t_token *token);
t_cmd	*add_cmd(t_cmd *cmd, t_slice *cmd_argv);
void	free_cmd_list(t_cmd **cmd);

#endif
