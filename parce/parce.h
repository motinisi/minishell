/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:29 by timanish          #+#    #+#             */
/*   Updated: 2024/11/15 19:45:11 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCE_H
# define PARCE_H

# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define NULL_CHAR 1

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

t_token	*tokenize(char *input);
int		input_split(char cmp);
t_token	*del_space_char(t_token *token);
#endif