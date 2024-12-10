/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:55:00 by rogiso            #+#    #+#             */
/*   Updated: 2024/06/24 22:55:00 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;

	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	diff = (int)((unsigned char)*s1 - (unsigned char)*s2);
	return (diff);
}
