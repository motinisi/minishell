/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:41:17 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/29 20:41:18 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int num, int fd)
{
	int		cnt;
	int		sign;
	char	num_str[10];

	sign = 1;
	if (num < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	cnt = sizeof(num_str);
	while (1)
	{
		cnt--;
		num_str[cnt] = num % 10 * sign + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	write(fd, &num_str[cnt], sizeof(num_str) - cnt);
}
