/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:16:09 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/18 15:16:11 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*my_strdup(const char *str)
{
	size_t	size;
	char	*dest;

	if (str == NULL)
		return (NULL);
	size = my_strlen(str) + 1;
	dest = (char *)malloc(size);
	if (dest == NULL)
		return (NULL);
	my_strlcpy(dest, str, size);
	return (dest);
}
