/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:47 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/09 13:17:48 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	count_digit(long num, int base_value);
static char	*initialize_num_str(long num, int *digit_cnt, int *sign);

char	*ft_convert_num(long num, int base_value, int is_upper)
{
	int		sign;
	int		digit_cnt;
	char	*base;
	char	*num_str;

	base = "0123456789abcdef";
	if (is_upper == 1)
		base = "0123456789ABCDEF";
	digit_cnt = count_digit(num, base_value);
	num_str = initialize_num_str(num, &digit_cnt, &sign);
	if (num_str == NULL)
		return (NULL);
	while (1)
	{
		num_str[digit_cnt] = base[num % base_value * sign];
		num /= base_value;
		digit_cnt--;
		if (num == 0)
			break ;
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

char	*initialize_num_str(long num, int *digit_cnt, int *sign)
{
	char	*num_str;

	num_str = (char *)malloc(sizeof(char) * (*digit_cnt + 1));
	if (num_str == NULL)
		return (NULL);
	num_str[*digit_cnt] = '\0';
	(*digit_cnt)--;
	*sign = 1;
	if (num < 0)
	{
		*sign = -1;
		num_str[0] = '-';
	}
	return (num_str);
}
