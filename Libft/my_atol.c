/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:52:00 by rogiso            #+#    #+#             */
/*   Updated: 2024/07/20 16:52:00 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	my_atol(const char *str)
{
	int		sign;
	long	digit;
	long	decimal;

	sign = 1;
	decimal = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		digit = (*str - '0') * sign;
		if (sign == 1 && decimal > (LONG_MAX - digit) / 10)
			return (LONG_MAX);
		else if (sign == -1 && decimal < (LONG_MIN - digit) / 10)
			return (LONG_MIN);
		decimal = (decimal * 10) + digit;
		str++;
	}
	return (decimal);
}
