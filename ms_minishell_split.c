/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:16:59 by timanish          #+#    #+#             */
/*   Updated: 2024/12/05 14:33:49 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_tokenize.h>

char	**minishell_split(const char *str, char *sep, int has_sep)
{
	size_t	words_cnt;
	char	**strarr;

	if (str == NULL)
		return (NULL);
	words_cnt = minishell_count_words_str(str, sep, has_sep);
	strarr = (char **)ft_calloc(words_cnt + 1, sizeof(char *));
	if (strarr == NULL)
		return (NULL);
	if (minishell_fill_strarr(strarr, str, sep, has_sep) == -1)
	{
		my_strarr_free(strarr);
		strarr = NULL;
	}
	return (strarr);
}

const char	*quote_handling(const char *str)
{
	size_t	i;
	char	quote;

	if (str[0] == '"')
		quote = '"';
	else if (str[0] == '\'')
		quote = '\'';
	else
		return (++str);
	str++;
	i = 0;
	while (*str)
	{
		if (*str == quote)
		{
			str++;
			return (str);
		}
		str++;
	}
	return (str);
}

int	minishell_fill_strarr(
	char **strarr, const char *str, char *sep, int has_sep)
{
	const char	*start;

	start = str;
	while (*str)
	{
		if (ft_strchr(sep, *str) == NULL)
			start = str;
		while (*str && ft_strchr(sep, *str) == NULL)
		{
			// str++;
			str = quote_handling(str);
		}
		if (str - start != 0 && (ft_strchr(sep, *str) != NULL || *str == '\0'))
		{
			*strarr = ft_strndup(start, str - start);
			if (*(strarr++) == NULL)
				return (-1);
		}
		while (*str && ft_strchr(sep, *str) != NULL)
		{
			if (has_sep == 1 && !ft_isspace(*str))
				*strarr = ft_strndup(str, 1);
			if (has_sep == 1 && !ft_isspace(*str) && *(strarr++) == NULL)
				return (-1);
			str++;
		}
	}
	return (1);
}

size_t	quote_handling_word(const char *str, size_t cnt)
{
	char	quote;

	if (str[cnt] == '"')
		quote = '"';
	else if (str[cnt] == '\'')
		quote = '\'';
	else
		return (++cnt);
	cnt++;
	while (str[cnt])
	{
		if (str[cnt] == quote)
		{
			cnt++;
			return (cnt);
		}
		cnt++;
	}
	return (cnt);
}

size_t	minishell_count_words_str(const char *str, char *sep, int has_sep)
{
	size_t	cnt;
	size_t	words_cnt;

	cnt = 0;
	words_cnt = 0;
	if (str == NULL)
		return (words_cnt);
	while (str[cnt])
	{
		if (ft_strchr(sep, str[cnt]) == NULL)
			words_cnt++;
		while (str[cnt] && ft_strchr(sep, str[cnt]) == NULL)
		{
			cnt = quote_handling_word(str, cnt);
			// cnt++;
		}
		while (str[cnt] && ft_strchr(sep, str[cnt]) != NULL)
		{
			if (has_sep == 1 && !ft_isspace(str[cnt]))
				words_cnt++;
			cnt++;
		}
	}
	return (words_cnt);
}
