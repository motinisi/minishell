/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:44:06 by rogiso            #+#    #+#             */
/*   Updated: 2024/06/05 17:44:07 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *str, size_t len)
{
	char	*dest;

	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, str, len + 1);
	return (dest);
}
