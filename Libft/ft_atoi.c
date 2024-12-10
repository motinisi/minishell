/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:52:09 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/24 20:52:10 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	digit;
	long	decimal;

	sign = 1;
	decimal = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		digit = (*str - '0') * sign;
		if (sign == 1 && decimal > (LONG_MAX - digit) / 10)
			return ((int)LONG_MAX);
		else if (sign == -1 && decimal < (LONG_MIN - digit) / 10)
			return ((int)LONG_MIN);
		decimal = (decimal * 10) + digit;
		str++;
	}
	return ((int)decimal);
}
