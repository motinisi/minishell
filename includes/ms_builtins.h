/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:14:09 by timanish          #+#    #+#             */
/*   Updated: 2024/12/10 15:33:00 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include <minishell.h>
# include <stdio.h>

void	builtin_cmd(t_cmd	*cmd, char**envp);
int		builtin_echo(char **cmd);
int		builtin_pwd(char **cmd);

#endif