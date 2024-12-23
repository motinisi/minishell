/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:25:42 by rogiso            #+#    #+#             */
/*   Updated: 2024/07/27 19:25:42 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
	{
		return (1);
	}
	return (0);
}
