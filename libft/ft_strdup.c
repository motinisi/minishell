/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:08:49 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/25 18:08:50 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(str) + 1;
	dest = (char *)malloc(size);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, str, size);
	return (dest);
}
