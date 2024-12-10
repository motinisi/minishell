/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:42:22 by rogiso            #+#    #+#             */
/*   Updated: 2024/11/22 01:42:22 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	fill_strarr(char **strarr, const char *str, char *sep, int has_sep);

char	**my_split(const char *str, char *sep, int has_sep)
{
	size_t	words_cnt;
	char	**strarr;

	if (str == NULL)
		return (NULL);
	words_cnt = my_count_words_str(str, sep, has_sep);
	strarr = (char **)ft_calloc(words_cnt + 1, sizeof(char *));
	if (strarr == NULL)
		return (NULL);
	if (fill_strarr(strarr, str, sep, has_sep) == -1)
	{
		my_strarr_free(strarr);
		strarr = NULL;
	}
	return (strarr);
}

static int	fill_strarr(char **strarr, const char *str, char *sep, int has_sep)
{
	const char	*start;

	start = str;
	while (*str)
	{
		if (ft_strchr(sep, *str) == NULL)
			start = str;
		while (*str && ft_strchr(sep, *str) == NULL)
			str++;
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
