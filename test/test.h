/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:29 by timanish          #+#    #+#             */
/*   Updated: 2024/11/13 17:47:36 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

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

#endif