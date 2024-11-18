/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:08 by timanish          #+#    #+#             */
/*   Updated: 2024/11/17 19:39:17 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parce.h"

t_token	*del_null_token(t_token *token)
{
	size_t	i;
	t_token	*head;

	head = token;
	i = 0;
	if (!token)
		return (0);
	while (token)
	{
		i ++;
		if (token->word[0] == '\0')
			break ;
		token = token->next;
	}
	if (token && token->word[0] == '\0')
	{
		free(token);
		token = head;
		while (--i)
			token->next = NULL;
	}
	return (head);
}

int	main(void)
{
	char	*input;
	t_token	*token;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
		{
			printf("/n");
			break ;
		}
		token = tokenize(input);
		// token = del_null_token(token);
		while (token)
		{
			if (token->word[0] == '\0')
				printf("syutann\n");
			else
				printf("word:%s\n", token->word);
			token = token->next;
		}
		if (*input)
			add_history(input);
		free(input);
	}
	return (0);
}
