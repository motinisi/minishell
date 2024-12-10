/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:38:54 by rogiso            #+#    #+#             */
/*   Updated: 2024/09/04 20:38:54 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_digit(long num, int base_value);
static int	get_base_value(const char *base);

char	*my_ltoa_base(long num, char *base)
{
	int		sign;
	int		digit;
	int		base_value;
	char	*num_str;

	sign = 1;
	base_value = get_base_value(base);
	if (base_value <= 1)
		return (NULL);
	digit = count_digit(num, base_value) - 1;
	num_str = (char *)ft_calloc(digit + 2, sizeof(char));
	if (num_str == NULL)
		return (NULL);
	if (num < 0)
	{
		sign = -1;
		num_str[0] = '-';
	}
	while ((sign == 1 && 0 <= digit) || (sign == -1 && 1 <= digit))
	{
		num_str[digit] = base[num % base_value * sign];
		num /= base_value;
		digit--;
	}
	return (num_str);
}

static int	count_digit(long num, int base_value)
{
	int	digit;

	digit = 0;
	if (num < 0)
		digit++;
	while (1)
	{
		num /= base_value;
		digit++;
		if (num == 0)
			break ;
	}
	return (digit);
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
