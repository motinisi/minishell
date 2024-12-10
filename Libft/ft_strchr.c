/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:44:57 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/18 11:44:58 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *str, int word)
{
	char	c_word;

	c_word = (char)word;
	while (*str)
	{
		if (*str == c_word)
			return ((char *)str);
		str++;
	}
	if (*str == c_word)
		return ((char *)str);
	return (NULL);
}
