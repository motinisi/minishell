/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:25:57 by timanish          #+#    #+#             */
/*   Updated: 2024/11/19 20:32:13 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parce.h"
#include <stdio.h>

int	input_split(char cmp)
{
	static char	split_char[] = {'|', '>', ' '};
	size_t		i;

	i = 0;
	while (split_char[i])
	{
		if (cmp == split_char[i])
			return (1);
		i++;
	}
	return (0);
}

static void	handle_quotes(char *input, size_t *i)
{
	(*i)++;
	while (input[*i] && (input[*i] != '\"' && input[*i] != '\''))
		(*i)++;
}

// static void	handle_split(t_token **token, char *input, size_t *i,
// 		size_t *head)
// {
// 	(*token)->word = (char *)malloc(sizeof(char) * (*i - *head + 1));
// 	ft_strlcpy((*token)->word, &input[*head], *i - *head + 1);
// 	if (input[*i] != input[*i + 1] && input[*i] != ' ')
// 	{
// 		(*token)->next = (t_token *)malloc(sizeof(t_token));
// 		*token = (*token)->next;
// 		*token = make_split_strut(*token, input, *i, SPLIT_CHAR);
// 	}
// 	else if (input[*i] != ' ')
// 	{
// 		(*token)->next = (t_token *)malloc(sizeof(t_token));
// 		*token = (*token)->next;
// 		*token = make_split_strut(*token, input, *i, SPLIT_CHAR * 2);
// 		(*i)++;
// 	}
// 	*head = *i + 1;
// }

void	make_split_strut(t_token **token, char *input, size_t i, int split_char)
{
	char	*word;

	if (!i)
		return ;
	word = (char *)malloc(sizeof(char) * split_char + NULL_CHAR);
	ft_strlcpy(word, &input[i], split_char + NULL_CHAR);
	token_add_back(token, word);
}

static void	*handle_last_token(t_token **token, char *input, size_t i,
		size_t head)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (i - head + 1));
	ft_strlcpy(word, &input[head], i - head + 1);
	token_add_back(token, word);
	return (0);
}

void	*handle_split(t_token **token, char *input, size_t *i, size_t *head)
{
	char	*word;

	if (*i == 0)
		word = (char *)malloc(sizeof(char) * (1 + 1));
	else
		word = (char *)malloc(sizeof(char) * (*i - *head + 1));
	ft_strlcpy(word, &input[*head], ft_strlen(word) + 1);
	if (*head == 0)
		*token = token_new(word);
	else
		token_add_back(token, word);
	if (input[*i] != input[*i + 1] && input[*i] != ' ')
		make_split_strut(token, input, *i, SPLIT_CHAR);
	else if (input[*i] != ' ')
	{
		make_split_strut(token, input, *i, SPLIT_CHAR * 2);
		*i = *i + 1;
	}
	*head = *i + 1;
	return (0);
}

t_token	*tokenize(char *input)
{
	t_token	*token;
	size_t	head;
	size_t	i;

	token = NULL;
	if (*input == '\0')
		return (0);
	i = 0;
	head = 0;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
			handle_quotes(input, &i);
		if (input_split(input[i]))
			handle_split(&token, input, &i, &head);
		i++;
		if (!input[i])
			handle_last_token(&token, input, i, head);
	}
	return (token);
}

// static void	handle_split(t_token **token, char *input, size_t *i,
// 		size_t *head)
// {
// 	if (*head != 0)
// 	{
// 		(*token)->next = (t_token *)malloc(sizeof(t_token));
// 		*token = (*token)->next;
// 	}
// 	if (*i != *head)
// 	{
// 		(*token)->word = (char *)malloc(sizeof(char) * (*i - *head + 1));
// 		ft_strlcpy((*token)->word, &input[*head], *i - *head + 1);
// 	}
// 	if (input[*i] != input[*i + 1] && input[*i] != ' ')
// 		*token = make_split_strut(*token, input, *i, SPLIT_CHAR);
// 	else if (input[*i] != ' ')
// 	{
// 		*token = make_split_strut(*token, input, *i, SPLIT_CHAR * 2);
// 		(*i)++;
// 	}
// 	*head = *i + 1;
// }

// static void	handle_last_token(t_token **token, char *input, size_t i,
// 		size_t head)
// {
// 	if (head != 0)
// 	{
// 		(*token)->next = (t_token *)malloc(sizeof(t_token));
// 		*token = (*token)->next;
// 	}
// 	(*token)->word = (char *)malloc(sizeof(char) * (i - head + 1));
// 	ft_strlcpy((*token)->word, &input[head], i - head + 1);
// }

// t_token	*tokenize(char *input)
// {
// 	t_token	*token;
// 	t_token	*head_token;
// 	size_t	head;
// 	size_t	i;

// 	token = (t_token *)malloc(sizeof(*token));
// 	head_token = token;
// 	i = 0;
// 	head = 0;

// 	while (input[i])
// 	{
// 		if (input[i] == '\"' || input[i] == '\'')
// 			handle_quotes(input, &i);
// 		if (input_split(input[i]))
// 			handle_split(&token, input, &i, &head);
// 		i++;
// 		if (!input[i] && i != head)
// 			handle_last_token(&token, input, i, head);
// 	}
// 	token->next = NULL;
// 	return (head_token);
// }

// t_token	*split_word(t_token *token, char *input, size_t *i, size_t *head)
// {
// 	if (*i != *head)
// 	{
// 		token->word = (char *)malloc(sizeof(char) * *i);
// 		ft_strlcpy(token->word, &input[*head], *i - *head + NULL_CHAR);
// 		token->next = (t_token *)malloc(sizeof(*token));
// 		token = token->next;
// 	}
// 	if (input[*i] != input[*i + 1] && input[*i] != ' ')
// 		token = make_split_strut(token, input, *i, SPLIT_CHAR);
// 	else if (input[*i] != ' ')
// 	{
// 		token = make_split_strut(token, input, *i, SPLIT_CHAR * 2);
// 		*i = *i + 1;
// 	}
// 	*head = *i + 1;
// 	return (token);
// }

// t_token	*tokenize(char *input)
// {
// 	t_token	*token;
// 	t_token	*head_token;
// 	size_t	head;
// 	size_t	i;

// 	token = (t_token *)malloc(sizeof(*token));
// 	head_token = token;
// 	i = 0;
// 	head = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '\"' || input[i] == '\'')
// 		{
// 			i ++;
// 			while (input[i] && (input[i] != '\"' && input[i] != '\''))
// 				i ++;
// 		}
// 		if (input_split(input[i]))
// 		{
// 			split_word(token, input, &i, &head);
// 			if (i != head)
// 			{
// 				token->word = (char *)malloc(sizeof(char) * i);
// 				ft_strlcpy(token->word, &input[head], i - head + NULL_CHAR);
// 				token->next = (t_token *)malloc(sizeof(*token));
// 				token = token->next;
// 			}
// 			if (input[i] != input[i + 1] && input[i] != ' ')
// 				token = make_split_strut(token, input, i, SPLIT_CHAR);
// 			else if (input[i] != ' ')
// 			{
// 				token = make_split_strut(token, input, i, SPLIT_CHAR * 2);
// 				i ++;
// 			}
// 			head = i + 1;
// 		}
// 		i ++;
// 		if (!input[i])
// 		{
// 			token->word = (char *)malloc(sizeof(char) * (i - head + 1));
// 			ft_strlcpy(token->word, &input[head], i - head + 1);
// 		}
// 	}
// 	token->next = NULL;
// 	return (head_token);
// }