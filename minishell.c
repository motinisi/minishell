/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:55:04 by rogiso            #+#    #+#             */
/*   Updated: 2024/12/10 15:28:19 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_tokenize.h>
#include <ms_pipe.h>
#include <ms_builtins.h>


int	main(int argc, char **argv, char **envp)
{
	t_token *token;
	t_cmd	*cmd;
	char 	*test_line;

	if (argc != 1 || argv == NULL || envp == NULL)
		return (1);
	while (1)
	{
		test_line = readline("minishell$ ");
		if (!test_line)
		{
			rl_clear_history();
			break ;
		}
		token = operate_readline(test_line);
		token = token_expand(token, envp);
		cmd = generate_cmd_list(token);
		builtin_cmd(cmd, envp);
		free_token_list(&token, 1);
		free_cmd_list(&cmd);
	}
	return (0);
}
