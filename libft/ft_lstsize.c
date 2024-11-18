/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:47:50 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/03 12:47:51 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lstsize(t_list *lst)
{
	int		lst_cnt;

	lst_cnt = 0;
	while (lst)
	{
		lst_cnt++;
		lst = lst->next;
	}
	return (lst_cnt);
}
