/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:41:33 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/29 19:41:35 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int		cnt;

	cnt = 0;
	if (str == NULL || f == NULL)
		return ;
	while (str[cnt])
	{
		f(cnt, &str[cnt]);
		cnt++;
	}
}
