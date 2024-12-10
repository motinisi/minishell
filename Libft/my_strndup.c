/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:42:25 by rogiso            #+#    #+#             */
/*   Updated: 2024/06/05 17:42:28 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*my_strndup(const char *str, size_t len)
{
	char	*dest;

	if (str == NULL)
		return (NULL);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	my_strlcpy(dest, str, len + 1);
	return (dest);
}
