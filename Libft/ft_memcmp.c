/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:41:22 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/22 13:41:23 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			cnt;
	unsigned char	*us_s1;
	unsigned char	*us_s2;

	cnt = 0;
	us_s1 = (unsigned char *)s1;
	us_s2 = (unsigned char *)s2;
	while (cnt < len)
	{
		if (us_s1[cnt] != us_s2[cnt])
		{
			return ((int)(us_s1[cnt] - us_s2[cnt]));
		}
		cnt++;
	}
	return (0);
}
