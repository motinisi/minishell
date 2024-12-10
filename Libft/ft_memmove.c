/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:17:35 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/22 19:17:36 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			cnt;
	unsigned char	*us_dest;
	unsigned char	*us_src;

	cnt = 0;
	us_dest = (unsigned char *)dest;
	us_src = (unsigned char *)src;
	if (dest < src)
	{
		while (cnt < len)
		{
			us_dest[cnt] = us_src[cnt];
			cnt++;
		}
	}
	else if (dest > src)
	{
		while (0 < len)
		{
			us_dest[len - 1] = us_src[len - 1];
			len--;
		}
	}
	return (dest);
}
