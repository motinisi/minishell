/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:56:38 by rogiso            #+#    #+#             */
/*   Updated: 2024/12/09 17:55:54 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_tokenize.h>
#include <ms_signal.h>


// t_token	*operate_readline(void)
t_token	*operate_readline(char *line)
{
	// char	*line;
	t_token	*token;

	// line = readline("minishell$ ");
	if (validate_syntax(line))
	{
		printf("ms_tool.c :48l  ---validate error---\n");
		return (NULL);
	}
	token = NULL;
	if (line == NULL)
		return (NULL);
	if (*line)
	{
		add_history(line);
		token = tokenize(line);
	}
	free(line);
	return (token);
}

char	*get_env_value(char **envp, char *env_key)
{
	size_t	len;

	len = my_strlen(env_key);
	if (len == 0)
		return (NULL);
	while (*envp)
	{
		if (ft_strncmp(*envp, env_key, len) == 0 && *(*envp + len) == '=')
			return (*envp + len + 1);
		envp++;
	}
	return (NULL);
}

t_token	*del_quote(t_token *token)
{
	char	*word;
	char	*re;
	t_token	*head;
	int		in_quote;

	head = token;
	while (token)
	{
		word = token->word;
		in_quote = 0;
		re = (char *)malloc(sizeof(char) * (ft_strlen(word) + 1));
		if (!re)
			return (NULL);
		re = skip_quote(word, re, in_quote);
		free(token->word);
		token->word = re;
		token = token->next;
	}
	return (head);
}

char	*skip_quote(char *word, char *re, int in_quote)
{
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	while (word[i])
	{
		if (!in_quote && (word[i] == '"' || word[i] == '\''))
		{
			in_quote = 1;
			quote = word[i];
			i++;
		}
		else if (in_quote && word[i] == quote)
		{
			in_quote = 0;
			i++;
		}
		else
			re[j++] = word[i++];
	}
	re[j] = '\0';
	return (re);
}

// char	**minishell_split(const char *str, char *sep, int has_sep)
// {
// 	size_t	words_cnt;
// 	char	**strarr;

// 	if (str == NULL)
// 		return (NULL);
// 	words_cnt = minishell_count_words_str(str, sep, has_sep);
// 	strarr = (char **)ft_calloc(words_cnt + 1, sizeof(char *));
// 	if (strarr == NULL)
// 		return (NULL);
// 	if (minishell_fill_strarr(strarr, str, sep, has_sep) == -1)
// 	{
// 		my_strarr_free(strarr);
// 		strarr = NULL;
// 	}
// 	return (strarr);
// }

// const char	*quote_handling(const char *str)
// {
// 	size_t	i;
// 	char	quote;

// 	if (str[0] == '"')
// 		quote = '"';
// 	else if (str[0] == '\'')
// 		quote = '\'';
// 	else
// 		return (++str);
// 	str++;
// 	i = 0;
// 	while (*str)
// 	{
// 		if (*str == quote)
// 		{
// 			str++;
// 			return (str);
// 		}
// 		str++;
// 	}
// 	return (str);
// }

// int	minishell_fill_strarr(char **strarr, const char *str, char *sep,
// 		int has_sep)
// {
// 	const char	*start;

// 	start = str;
// 	while (*str)
// 	{
// 		if (ft_strchr(sep, *str) == NULL)
// 			start = str;
// 		while (*str && ft_strchr(sep, *str) == NULL)
// 		{
// 			// str++;
// 			str = quote_handling(str);
// 		}
// 		if (str - start != 0 && (ft_strchr(sep, *str) != NULL || *str == '\0'))
// 		{
// 			*strarr = ft_strndup(start, str - start);
// 			if (*(strarr++) == NULL)
// 				return (-1);
// 		}
// 		while (*str && ft_strchr(sep, *str) != NULL)
// 		{
// 			if (has_sep == 1 && !ft_isspace(*str))
// 				*strarr = ft_strndup(str, 1);
// 			if (has_sep == 1 && !ft_isspace(*str) && *(strarr++) == NULL)
// 				return (-1);
// 			str++;
// 		}
// 	}
// 	return (1);
// }

// size_t	quote_handling_word(const char *str, size_t cnt)
// {
// 	char	quote;

// 	if (str[cnt] == '"')
// 		quote = '"';
// 	else if (str[cnt] == '\'')
// 		quote = '\'';
// 	else
// 		return (++cnt);
// 	cnt++;
// 	while (str[cnt])
// 	{
// 		if (str[cnt] == quote)
// 		{
// 			cnt++;
// 			return (cnt);
// 		}
// 		cnt++;
// 	}
// 	return (cnt);
// }

// size_t	minishell_count_words_str(const char *str, char *sep, int has_sep)
// {
// 	size_t	cnt;
// 	size_t	words_cnt;

// 	cnt = 0;
// 	words_cnt = 0;
// 	if (str == NULL)
// 		return (words_cnt);
// 	while (str[cnt])
// 	{
// 		if (ft_strchr(sep, str[cnt]) == NULL)
// 			words_cnt++;
// 		while (str[cnt] && ft_strchr(sep, str[cnt]) == NULL)
// 		{
// 			cnt = quote_handling_word(str, cnt);
// 			// cnt++;
// 		}
// 		while (str[cnt] && ft_strchr(sep, str[cnt]) != NULL)
// 		{
// 			if (has_sep == 1 && !ft_isspace(str[cnt]))
// 				words_cnt++;
// 			cnt++;
// 		}
// 	}
// 	return (words_cnt);
// }

// size_t	env_len(char **envp)
// {
// 	size_t	total_len;
// 	size_t	i;

// 	total_len = 0;
// 	i = 0;
// 	while (envp[i])
// 	{
// 		total_len += ft_strlen(envp[i]);
// 		i ++;
// 	}
// 	return (total_len);
// }

// t_token	*token_expand(t_token *token, char **envp)
// {
// 	t_token	*head;
// 	char	*word;
// 	size_t	quote_cnt;
// 	char	*key;
// 	size_t	key_i;
// 	char	*value;
// 	char	*re;

// 	head = token;
// 	size_t i, j, k;
// 	while (token)
// 	{
// 		word = token->word;
// 		printf("ms_tool.c :233l -> word: %s\n", word);
// 		quote_cnt = 0;
// 		i = 0;
// 		k = 0;
// 		j = 0;
// 		key = (char *)malloc(sizeof(char) * (ft_strlen(word) + 1));
// 		re = (char *)malloc(sizeof(char) * (env_len(envp) + 1));
// 		if (key == NULL || re == NULL)
// 		{
// 			free(key);
// 			free(re);
// 			return (NULL);
// 		}
// 		while (word[i])
// 		{
// 			if (word[i] == '\'')
// 				quote_cnt++;
// 			if (quote_cnt % 2 == 0 && word[i] == '$')
// 			{
// 				key_i = i + 1;
// 				j = 0;
// 				while (word[key_i] && word[key_i] != ' ' && word[key_i] != '"'
// 					&& word[key_i] != '\'' && word[key_i] != '|')
// 				{
// 					key[j] = word[key_i];
// 					j++;
// 					key_i++;
// 				}
// 				key[j] = '\0';
// 				value = get_env_value(envp, key);
// 				printf("ms_tool.c :258l -> value: %s\n", value);
// 				if (value)
// 				{
// 					j = 0;
// 					printf("is so far okokokoko\n");
// 					printf ("%zu\n", k);
// 					printf ("%c\n", re[k]);
// 					while (value[j])
// 					{
// 						re[k] = value[j];
// 						j++;
// 						k++;
// 					}
// 				}
// 				i ++;
// 			}
// 			re[k] = word[i];
// 			k++;
// 			i++;
// 			re[k] = '\0';
// 			printf("ms_tool.c :264l -> re: %s\n", re);
// 		}
// 		re[k] = '\0';
// 		free(token->word);
// 		token->word = ft_strdup(re);
// 		free(re);
// 		free(key);
// 		token = token->next;
// 	}
// 	return (head);
// }
