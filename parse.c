/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:25:57 by timanish          #+#    #+#             */
/*   Updated: 2024/11/14 22:28:40 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// t_token	*tokenize(char *input)
// {
// 	t_token	*token;
// 	t_token	*head;
// 	char	**word;
// 	size_t	i;

// 	token = (t_token *)malloc(sizeof(*token));
// 	head = token;

// 	i  = 0;
// 	whiel(input[i])
// 	{

// 	}

// 	word = ft_split(input, ' ');
// 	i = 0;
// 	while (word[i])
// 	{
// 		token->word = word[i];
// 		i++;
// 		if (word[i])
// 		{
// 			token->next = (t_token *)malloc(sizeof(*token));
// 			token = token->next;
// 		}
// 		else
// 			token->next = NULL;
// 	}
// 	free(word);
// 	return (head);
// }


#include <stdio.h>
#include "test.h"


int	input_split(char cmp)
{
	static char	split_char[] = {'|', '>', ' '};
	size_t		i;

	i = 0;
	while (split_char[i])
	{
		if (cmp == split_char[i])
			return (1);
		i ++;
	}
	return (0);
}


t_token	*tokenize(char *input)
{
	t_token	*token;
	t_token	*head_token;
	size_t	head;
	size_t	i;

	token = (t_token *)malloc(sizeof(*token));
	head_token = token;
	i = 0;
	while (input[i])
	{
		if (input_split(input[i]))
		{
			token->word = (char *)malloc(sizeof(char) * i);
			ft_strlcpy(token->word, input, i + 1);
			token->next = (t_token *)malloc(sizeof(*token));
			token = token->next;
			if (input[i] != input[i + 1])
			{
				token->word = (char *)malloc(sizeof(char) * 2);
				ft_strlcpy(token->word, &input[i], 2);
				token->next = (t_token *)malloc(sizeof(*token));
				token = token->next;
			}
			else
			{
				token->word = (char *)malloc(sizeof(char) * 3);
				ft_strlcpy(token->word, &input[i - 1], 3);
				token->next = (t_token *)malloc(sizeof(*token));
				token = token->next;
			}
			head = i + 1;
		}
		i ++;
		if (!input[i])
		{
			token->word = (char *)malloc(sizeof(char) * (i - head + 1));
			ft_strlcpy(token->word, &input[head], i - head + 1);
		}
	}
	token->next = NULL;
	return (head_token);
}


// int	main()
// {
// 	printf("%d\n", input_split(' '));
// 	return (0);
// }

