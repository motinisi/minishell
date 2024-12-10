/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:12:57 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/29 12:12:59 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub_str;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) <= start)
	{
		len = 0;
		start = ft_strlen(str);
	}
	else if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, str + start, len + 1);
	return (sub_str);
}
