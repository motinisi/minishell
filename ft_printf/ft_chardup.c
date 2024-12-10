/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chardup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:34:15 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/09 17:34:21 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_chardup(const char c)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	if (dest == NULL)
		return (NULL);
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}
