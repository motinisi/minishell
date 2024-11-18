/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:00:29 by timanish          #+#    #+#             */
/*   Updated: 2024/11/18 20:08:10 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parce.h"

t_token	*token_last(t_token *token)
{
	if (token == NULL)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

t_token	*token_new(char	*word)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->word = word;
	token->next = NULL;
	return (token);
}

t_token	*token_add_back(t_token *token, char *word)
{
	t_token	*new_token;
	t_token	*head;

	head = token;
	new_token = token_new(word);
	token = token_last(token);
	if (!token)
		return (new_token);
	token->next = new_token;
	return (head);
}

