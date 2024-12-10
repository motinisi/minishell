/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:21:45 by rogiso            #+#    #+#             */
/*   Updated: 2024/12/04 16:07:06 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_tokenize.h>

t_token	*tokenize(char *line)
{
	size_t	cnt;
	char	**words;
	t_token	*token;
	t_token	*token_head;

	cnt = 0;
	words = minishell_split(line, " |", 1);
	token = NULL;
	token_head = NULL;
	while (words && words[cnt])
	{
		token = add_token(token);
		if (token == NULL)
		{
			my_strarr_free(words);
			free_token_list(&token_head, 0);
			return (NULL);
		}
		if (token_head == NULL)
			token_head = token;
		token->word = words[cnt];
		cnt++;
	}
	free(words);
	return (token_head);
}

t_token	*add_token(t_token *token)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->word = NULL;
	new_token->kind = NONE;
	new_token->next = NULL;
	if (token)
		token->next = new_token;
	return (new_token);
}

void	free_token_list(t_token **token, int should_free_word)
{
	t_token	*token_next;

	while (token && *token)
	{
		token_next = (*token)->next;
		if (should_free_word == 1)
			free((*token)->word);
		free(*token);
		*token = token_next;
	}
}
