/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:40:49 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/22 13:40:50 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *dest, size_t len)
{
	size_t			cnt;
	unsigned char	*dest_ptr;

	cnt = 0;
	dest_ptr = (unsigned char *)dest;
	while (cnt < len)
	{
		dest_ptr[cnt] = 0;
		cnt++;
	}
}
