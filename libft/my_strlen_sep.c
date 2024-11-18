/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlen_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:45:24 by rogiso            #+#    #+#             */
/*   Updated: 2024/09/22 23:45:24 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	my_strlen_sep(const char *str, const char sep)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len] && str[len] != sep)
	{
		len++;
	}
	return (len);
}
