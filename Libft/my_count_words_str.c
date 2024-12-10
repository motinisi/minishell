/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_count_words_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:42:00 by rogiso            #+#    #+#             */
/*   Updated: 2024/11/22 14:42:00 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	my_count_words_str(const char *str, char *sep, int has_sep)
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
			cnt++;
		while (str[cnt] && ft_strchr(sep, str[cnt]) != NULL)
		{
			if (has_sep == 1 && !ft_isspace(str[cnt]))
				words_cnt++;
			cnt++;
		}
	}
	return (words_cnt);
}
