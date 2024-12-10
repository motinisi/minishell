/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:32:21 by rogiso            #+#    #+#             */
/*   Updated: 2024/11/27 18:32:21 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_pipe.h>

t_cmd	*generate_cmd_list(t_token *token)
{
	t_cmd	*cmd;
	t_cmd	*cmd_head;
	t_slice	*cmd_argv;

	cmd = NULL;
	cmd_head = NULL;
	while (token)
	{
		while (token && *(token->word) == '|')
			token = token->next;
		if (token == NULL)
			return (NULL);
		cmd_argv = generate_cmd_argv(token);
		cmd = add_cmd(cmd, cmd_argv);
		if (cmd == NULL || cmd_argv == NULL)
			free_cmd_list(&cmd_head);
		else if (cmd_head == NULL)
			cmd_head = cmd;
		while (cmd_head && token && *(token->word) != '|')
			token = token->next;
	}
	return (cmd_head);
}

t_slice	*generate_cmd_argv(t_token *token)
{
	t_slice	*cmd_argv;

	cmd_argv = my_slice_create(sizeof(char *), 1, 0);
	if (cmd_argv == NULL)
		return (NULL);
	while (token && *(token->word) != '|' && cmd_argv->is_error == 0)
	{
		my_slice_append(cmd_argv, &token->word);
		token = token->next;
	}
	if (cmd_argv->is_error == 1)
		my_slice_free(&cmd_argv);
	return (cmd_argv);
}

t_cmd	*add_cmd(t_cmd *cmd, t_slice *cmd_argv)
{
	t_cmd	*new_cmd;

	if (cmd_argv == NULL)
		return (NULL);
	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (new_cmd == NULL)
		return (NULL);
	new_cmd->cmd_argv = cmd_argv;
	new_cmd->next = NULL;
	new_cmd->status = -1;
	if (cmd)
		cmd->next = new_cmd;
	return (new_cmd);
}

void	free_cmd_list(t_cmd **cmd)
{
	t_cmd	*cmd_next;

	while (cmd && *cmd)
	{
		cmd_next = (*cmd)->next;
		my_slice_free(&(*cmd)->cmd_argv);
		free(*cmd);
		*cmd = cmd_next;
	}
}
