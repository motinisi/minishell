/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:05:19 by timanish          #+#    #+#             */
/*   Updated: 2024/12/07 17:31:32 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

# include <minishell.h>
# include <signal.h>

/* ms_siganal_handlers.c */
void	validate_signal(void);
void	sigint_handle(int sig);
void	exit_shell(void);

#endif