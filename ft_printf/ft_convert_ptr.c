/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:50:14 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/11 18:50:15 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	count_digit(size_t num, int base_value);
static char	*initialize_num_str(int *digit_cnt);

char	*ft_convert_ptr(size_t num, int base_value, int is_upper)
{
	int		digit_cnt;
	char	*base;
	char	*num_str;

	base = "0123456789abcdef";
	if (is_upper == 1)
		base = "0123456789ABCDEF";
	digit_cnt = count_digit(num, base_value);
	num_str = initialize_num_str(&digit_cnt);
	if (num_str == NULL)
		return (NULL);
	while (1)
	{
		num_str[digit_cnt] = base[num % base_value];
		num /= base_value;
		digit_cnt--;
		if (num == 0)
			break ;
	}
	return (num_str);
}

static int	count_digit(size_t num, int base_value)
{
	int	digit;

	digit = 0;
	while (1)
	{
		num /= base_value;
		digit++;
		if (num == 0)
		{
			digit += 2;
			break ;
		}
	}
	return (digit);
}

static char	*initialize_num_str(int *digit_cnt)
{
	char	*num_str;

	num_str = (char *)malloc(*digit_cnt + 1);
	if (num_str == NULL)
		return (NULL);
	num_str[*digit_cnt] = '\0';
	(*digit_cnt)--;
	num_str[0] = '0';
	num_str[1] = 'x';
	return (num_str);
}
