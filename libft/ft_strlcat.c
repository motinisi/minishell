/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:23:37 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/22 22:23:38 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	if (dest)
		dest_len = ft_strlen(dest);
	else
		dest_len = 0;
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (src_len + size);
	}
	ft_strlcpy(dest + dest_len, src, size - dest_len);
	return (dest_len + src_len);
}
