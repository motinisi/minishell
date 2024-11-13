/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:27:08 by timanish          #+#    #+#             */
/*   Updated: 2024/11/13 14:31:17 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <strings.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "libft/libft.h"


enum	e_token_kind
{
	WORD,
	NAME,
	MATCHAR,
	OPE,
};
typedef enum e_token_kind	t_token_kind;


struct	s_token
{
	char					*word;
	t_token_kind			kind;
	struct s_token			*next;
};
typedef struct s_token		t_token;

char	*input_read(void)
{
	char	*input;

	while (1)
	{
		input = readline("c9r9s9% ");
		if (strlen(input))
			break ;
	}
	return (input);
}

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


int	main()
{
	char	*input;
	t_token	*token;
	
	input = input_read();
	token = tokenize(input);

	// printf("%s\n", token->word);

	while(token)
	{
		printf("token: %s\n", token->word);
		token = token->next;
	}
	return (0);
}
