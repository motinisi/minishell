/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 05:06:24 by rogiso            #+#    #+#             */
/*   Updated: 2024/09/04 05:06:24 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_base_value(const char *base);
static int	get_base_index(const char c, const char *base, int base_value);
static long	get_decimal(int sign, long digit, long decimal, int base_value);

long	my_atol_base(const char *str, const char *base)
{
	int		sign;
	long	decimal;
	int		index;
	int		base_value;

	sign = 1;
	decimal = 0;
	base_value = get_base_value(base);
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		index = get_base_index(*str, base, base_value);
		if (index == -1)
			return (0);
		decimal = get_decimal(sign, index * sign, decimal, base_value);
		if (decimal == LONG_MAX || decimal == LONG_MIN)
			return (decimal);
		str++;
	}
	return (decimal);
}

static int	get_base_value(const char *base)
{
	int	cnt1;
	int	cnt2;
	int	base_value;

	cnt1 = 0;
	base_value = (int)my_strlen(base);
	if (base_value <= 1)
		return (0);
	while (cnt1 < base_value)
	{
		cnt2 = cnt1 + 1;
		if (base[cnt1] == '+' || base[cnt1] == '-' || ft_isspace(base[cnt1]))
			return (0);
		while (cnt2 < base_value)
		{
			if (base[cnt1] == base[cnt2])
				return (0);
			cnt2++;
		}
		cnt1++;
	}
	return (base_value);
}

static int	get_base_index(const char c, const char *base, int base_value)
{
	int	index;

	index = 0;
	while (index < base_value)
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

static long	get_decimal(int sign, long digit, long decimal, int base_value)
{
	if (sign == 1 && decimal > (LONG_MAX - digit) / 10)
		return (LONG_MAX);
	else if (sign == -1 && decimal < (LONG_MIN - digit) / 10)
		return (LONG_MIN);
	else
		return ((decimal * base_value) + digit);
}
