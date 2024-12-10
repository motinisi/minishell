/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_count_words_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:25:33 by rogiso            #+#    #+#             */
/*   Updated: 2024/07/22 20:25:33 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	my_count_words_char(const char *str, char sep)
{
	size_t	cnt;
	size_t	words_cnt;

	cnt = 0;
	words_cnt = 0;
	if (str == NULL)
		return (words_cnt);
	while (str[cnt])
	{
		if (str[cnt] != sep)
			words_cnt++;
		while (str[cnt] && str[cnt] != sep)
			cnt++;
		while (str[cnt] && str[cnt] == sep)
			cnt++;
	}
	return (words_cnt);
}
