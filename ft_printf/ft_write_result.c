/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:14:43 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/08 21:14:45 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_write_result(t_text *text, ssize_t len)
{
	ssize_t	res_len;

	if (text->out_len == -1)
		return (text->out_len);
	res_len = write(1, text->result, len);
	if (res_len == -1)
		text->out_len = -1;
	else
		text->out_len += res_len;
	return (res_len);
}
