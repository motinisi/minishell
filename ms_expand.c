/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:45:06 by timanish          #+#    #+#             */
/*   Updated: 2024/12/09 17:27:01 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_tokenize.h>

size_t	env_len(char **envp)
{
	size_t	total_len;
	size_t	i;

	total_len = 0;
	i = 0;
	while (envp[i])
	{
		total_len += ft_strlen(envp[i]);
		i++;
	}
	return (total_len);
}

void	generate_key(char *key, char *word, size_t	*i);
size_t	value_in_result_token_word(char *value, char *re, size_t k);
void	generate_expand_token(char *word, char *key, char **envp, char *re);

t_token	*token_expand(t_token *token, char **envp)
{
	t_token	*head;
	char	*word;
	char	*key;
	char	*re;

	head = token;
	while (token)
	{
		word = token->word;
		printf("ms_tool.c :233l -> word: %s\n", word);
		key = (char *)malloc(sizeof(char) * (ft_strlen(word) + 1));
		if (!key)
			return (NULL);
		re = (char *)malloc(sizeof(char) * (env_len(envp) + 1));
		if (!re)
			return (free(key), NULL);
		generate_expand_token(word, key, envp, re);
		free(token->word);
		token->word = ft_strdup(re);
		free(re);
		free(key);
		token = token->next;
	}
	head = del_quote(head);
	return (head);
}

void	generate_key(char *key, char *word, size_t	*i)
{
	size_t	key_i;
	size_t	j;

	key_i = *i + 1;
	j = 0;
	while (word[key_i] && word[key_i] != ' ' && word[key_i] != '"'
		&& word[key_i] != '\'' && word[key_i] != '|')
	{
		key[j] = word[key_i];
		j++;
		key_i++;
	}
	key[j] = '\0';
	*i += ft_strlen(key);
}

size_t	value_in_result_token_word(char *value, char *re, size_t k)
{
	size_t	j;

	if (value)
	{
		j = 0;
		while (value[j])
		{
			re[k] = value[j];
			k ++;
			j ++;
		}
	}
	return (k);
}

void	generate_expand_token(char *word, char *key, char **envp, char *re)
{
	size_t	i;
	size_t	k;
	size_t	quote_cnt;
	char	*value;

	i = 0;
	k = 0;
	quote_cnt = 0;
	while (word[i])
	{
		if (word[i] == '\'')
			quote_cnt++;
		if (quote_cnt % 2 == 0 && word[i] == '$')
		{
			generate_key(key, word, &i);
			value = get_env_value(envp, key);
			k = value_in_result_token_word(value, re, k);
			i ++;
		}
		if (!word[i])
			break ;
		re[k ++] = word[i ++];
	}
	re[k] = '\0';
}
