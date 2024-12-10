/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:41:03 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/22 13:41:05 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			cnt;
	unsigned char	*us_dest;
	unsigned char	*us_src;

	if (!dest && !src)
	{
		return (NULL);
	}
	cnt = 0;
	us_dest = (unsigned char *)dest;
	us_src = (unsigned char *)src;
	while (cnt < len)
	{
		us_dest[cnt] = us_src[cnt];
		cnt++;
	}
	return (dest);
}
