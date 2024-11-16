/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:08 by timanish          #+#    #+#             */
/*   Updated: 2024/11/16 19:43:25 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parce.h"

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
		// token = del_space_char(token);
		while (token)
		{
			if (token->word == NULL)
				token->word = "nunununuunun";
			if (token->word[0] == '\0')
				token->word = "syuutann";
			printf("word:%s\n", token->word);
			token = token->next;
		}
		if (*input)
			add_history(input);
		free(input);
	}
	return (0);
}
