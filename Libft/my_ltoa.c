/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:52:00 by rogiso            #+#    #+#             */
/*   Updated: 2024/07/20 16:52:00 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_digit(long num);

char	*my_ltoa(long num)
{
	int		sign;
	int		digit;
	char	*num_str;

	sign = 1;
	digit = count_digit(num);
	num_str = (char *)ft_calloc(digit + 1, sizeof(char));
	if (num_str == NULL)
		return (NULL);
	digit--;
	if (num < 0)
	{
		sign = -1;
		num_str[0] = '-';
	}
	while (1)
	{
		num_str[digit] = num % 10 * sign + '0';
		num /= 10;
		digit--;
		if (num == 0)
			break ;
	}
	return (num_str);
}

static int	count_digit(long num)
{
	int	digit;

	digit = 0;
	if (num < 0)
		digit++;
	while (1)
	{
		num /= 10;
		digit++;
		if (num == 0)
			break ;
	}
	return (digit);
}
