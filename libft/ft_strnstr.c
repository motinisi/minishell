/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:21 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/24 16:34:23 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	size_t	cnt;
	size_t	target_len;

	cnt = 0;
	target_len = ft_strlen(target);
	if (str == NULL && len == 0)
		return (NULL);
	if (target[0] == '\0')
		return ((char *)str);
	while (str[cnt] && target_len <= len - cnt)
	{
		if (str[cnt] == target[0])
		{
			if (ft_strncmp(&str[cnt], target, target_len) == 0)
				return ((char *)&str[cnt]);
		}
		cnt++;
	}
	return (NULL);
}
