/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:27:07 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/26 15:27:09 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		set_each_str(char **strarr, const char *str, char sep);
static void		free_strarr(char **strarr);

char	**ft_split(const char *str, char sep)
{
	size_t	words_cnt;
	char	**strarr;

	if (str == NULL)
		return (NULL);
	words_cnt = my_count_words(str, sep);
	strarr = (char **)ft_calloc(words_cnt + 1, sizeof(char *));
	if (strarr == NULL)
		return (NULL);
	if (set_each_str(strarr, str, sep) == -1)
	{
		free_strarr(strarr);
		strarr = NULL;
	}
	return (strarr);
}

static int	set_each_str(char **strarr, const char *str, char sep)
{
	int	cnt;
	int	start;

	cnt = 0;
	start = 0;
	while (str[cnt])
	{
		if (str[cnt] != sep)
			start = cnt;
		while (str[cnt] && str[cnt] != sep)
			cnt++;
		if (cnt != 0 && (str[cnt] == sep || str[cnt] == '\0'))
		{
			*strarr = ft_strndup(&str[start], cnt - start);
			if (*strarr == NULL)
				return (-1);
			strarr++;
		}
		while (str[cnt] && str[cnt] == sep)
			cnt++;
	}
	return (1);
}

static void	free_strarr(char **strarr)
{
	int	cnt;

	cnt = 0;
	while (strarr[cnt])
	{
		free(strarr[cnt]);
		cnt++;
	}
	free(strarr);
}
