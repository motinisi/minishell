/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:53:04 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/09 20:53:05 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_join_format(t_text *text, char *str, size_t len)
{
	int		cnt;
	ssize_t	diff_len;

	cnt = 0;
	diff_len = text->all_len - text->out_len;
	text->all_len += (ssize_t)len;
	if (SIZE < diff_len + (ssize_t)len)
	{
		ft_write_result(text, diff_len);
		if (text->out_len == -1)
			return ;
		while (SIZE < len - SIZE * cnt)
		{
			ft_memcpy(text->result, &str[SIZE * cnt++], SIZE);
			ft_write_result(text, SIZE);
			if (text->out_len == -1)
				return ;
		}
		ft_memcpy(text->result, &str[SIZE * cnt], len - SIZE * cnt);
	}
	else
		ft_memcpy(text->result + diff_len, str, len);
	free((void *)str);
}
