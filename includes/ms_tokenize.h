/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:57:25 by rogiso            #+#    #+#             */
/*   Updated: 2024/12/10 14:10:46 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_TOKENIZE_H
# define MS_TOKENIZE_H

# include <minishell.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ms_tokenize.c */
t_token		*tokenize(char *line);
t_token		*add_token(t_token *token);
void		free_token_list(t_token **token, int should_free_word);
int			minishell_fill_strarr(\
	char **strarr, const char *str, char *sep, int has_sep);
char		**minishell_split(const char *str, char *sep, int has_sep);
size_t		minishell_count_words_str(const char *str, char *sep, int has_sep);
char		**minishell_split(const char *str, char *sep, int has_sep);
const char	*quote_handling(const char *str);
int			minishell_fill_strarr(\
	char **strarr, const char *str, char *sep, int has_sep);
int			validate_quote(char *line);
int			validate_pipe(char *line);
int			validate_syntax(char *line);
t_token		*del_quote(t_token *token);
char		*skip_quote(char *word, char *re, int in_quote);
t_token		*token_expand(t_token *token, char **envp);

#endif
