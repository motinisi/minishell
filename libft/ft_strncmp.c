/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:20:03 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/18 15:20:09 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	cnt;
	int		diff;

	cnt = 0;
	while (cnt < len)
	{
		if (s1[cnt] != s2[cnt])
		{
			diff = (int)((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
			return (diff);
		}
		if (s1[cnt] == '\0' || s2[cnt] == '\0')
		{
			return (0);
		}
		cnt++;
	}
	return (0);
}
