/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:40:32 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/22 13:40:34 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *buffer, int src, size_t len)
{
	size_t			cnt;
	unsigned char	*us_buffer;
	unsigned char	us_src;

	cnt = 0;
	us_buffer = (unsigned char *)buffer;
	us_src = (unsigned char)src;
	while (cnt < len)
	{
		if (us_buffer[cnt] == us_src)
		{
			return (&us_buffer[cnt]);
		}
		cnt++;
	}
	return (NULL);
}
