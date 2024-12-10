/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:09:31 by rogiso            #+#    #+#             */
/*   Updated: 2024/09/22 16:09:31 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	my_error(char *message, int status, int error_num)
{
	char	*error_str;

	if (0 <= error_num)
	{
		error_str = strerror(error_num);
		ft_putstr_fd("\033[91mError\033[0m\n", 2);
		ft_putstr_fd("Message    : ", 2);
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("Description: ", 2);
		ft_putstr_fd(error_str, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("\033[91mError\033[0m\n", 2);
		ft_putstr_fd("Message: ", 2);
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(status);
}
