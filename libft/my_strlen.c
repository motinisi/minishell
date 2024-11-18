/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:49:54 by rogiso            #+#    #+#             */
/*   Updated: 2024/06/05 17:49:55 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	my_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len])
	{
		len++;
	}
	return (len);
}
