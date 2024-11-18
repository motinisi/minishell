/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:31:41 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/03 15:31:43 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_lst;
	t_list	*last_lst;
	t_list	*new_node;
	void	*f_content;

	first_lst = NULL;
	last_lst = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		f_content = f(lst->content);
		new_node = ft_lstnew(f_content);
		if (new_node == NULL)
		{
			free(f_content);
			ft_lstclear(&first_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&last_lst, new_node);
		if (first_lst == NULL)
			first_lst = last_lst;
		lst = lst->next;
	}
	return (first_lst);
}
