/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:47:06 by rogiso            #+#    #+#             */
/*   Updated: 2024/06/05 17:47:07 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	my_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cnt;
	size_t	src_len;

	cnt = 0;
	src_len = my_strlen(src);
	if (dest == NULL || size == 0)
		return (src_len);
	while (cnt < size - 1 && cnt < src_len)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (src_len);
}
