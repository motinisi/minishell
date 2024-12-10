/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:57:25 by rogiso            #+#    #+#             */
/*   Updated: 2024/12/09 17:49:18 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <ft_printf.h>

typedef enum	e_token_kind
{
	NONE,
	WORD,
	NAME,
	MATCHAR,
	OPE,
}	t_token_kind;

typedef struct	s_token
{
	char			*word;
	t_token_kind	kind;
	struct s_token	*next;
}	t_token;

typedef struct	s_cmd
{
	t_slice			*cmd_argv;
	int				status;
	struct s_cmd	*next;
}	t_cmd;

/* ms_tools.c */
t_token	*operate_readline(char *test_line);
// t_token	*operate_readline(void);
char	*get_env_value(char **envp, char *env_key);

#endif