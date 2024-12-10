/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:34:33 by timanish          #+#    #+#             */
/*   Updated: 2024/12/07 16:51:21 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_signal.h>
#include <ms_tokenize.h>

void	validate_signal(void)
{
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, SIG_IGN);
}

void	sigint_handle(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	exit_shell(void)
{
	rl_clear_history();
	exit(0);
}
