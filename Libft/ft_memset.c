/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:41:35 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/18 18:41:36 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *dest, int src, size_t len)
{
	size_t			cnt;
	unsigned char	*dest_ptr;
	unsigned char	us_src;

	cnt = 0;
	dest_ptr = (unsigned char *)dest;
	us_src = (unsigned char)src;
	while (cnt < len)
	{
		dest_ptr[cnt] = us_src;
		cnt++;
	}
	return (dest);
}
