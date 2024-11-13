/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:25:57 by timanish          #+#    #+#             */
/*   Updated: 2024/11/13 17:48:56 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_token	*tokenize(char *input)
{
	t_token	*token;
	t_token	*head;
	char	**word;
	size_t	i;

	token = (t_token *)malloc(sizeof(*token));
	head = token;
	word = ft_split(input, ' ');
	i = 0;
	while (word[i])
	{
		token->word = word[i];
		i++;
		if (word[i])
		{
			token->next = (t_token *)malloc(sizeof(*token));
			token = token->next;
		}
		else
			token->next = NULL;
	}
	free(word);
	return (head);
}
