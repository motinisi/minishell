/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:57:04 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/18 14:57:05 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int word)
{
	size_t	cnt;
	char	c_word;

	cnt = ft_strlen(str);
	c_word = (char)word;
	if (c_word == '\0')
	{
		return ((char *)&str[cnt]);
	}
	while (0 < cnt)
	{
		if (str[cnt - 1] == c_word)
		{
			return ((char *)&str[cnt - 1]);
		}
		cnt--;
	}
	return (NULL);
}
