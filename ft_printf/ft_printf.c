/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.C                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:24:46 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/06 20:24:47 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	initialize(t_text *text, size_t *cnt, size_t *start);
static void	convert_arg(t_text *text, char format);

int	ft_printf(const char *format, ...)
{
	t_text	text;
	size_t	cnt;
	size_t	start;
	size_t	len;

	initialize(&text, &cnt, &start);
	va_start(text.args_p, format);
	while (format[cnt])
	{
		if (format[cnt] == '%' && format[cnt + 1])
		{
			len = cnt - start;
			ft_join_format(&text, ft_substr(format, start, len), len);
			convert_arg(&text, format[++cnt]);
			start = cnt + 1;
		}
		if (format[cnt] == '\0')
			break ;
		cnt++;
	}
	len = cnt - start;
	ft_join_format(&text, ft_substr(format, start, len), len);
	ft_write_result(&text, text.all_len - text.out_len);
	va_end(text.args_p);
	return (text.all_len);
}

static void	initialize(t_text *text, size_t *cnt, size_t *start)
{
	*cnt = 0;
	*start = 0;
	text->all_len = 0;
	text->out_len = 0;
	text->result[0] = '\0';
}

static void	convert_arg(t_text *text, char format)
{
	char	*str;

	str = NULL;
	if (format == 'c')
		str = ft_chardup(va_arg(text->args_p, int));
	else if (format == 's')
		str = my_strdup(va_arg(text->args_p, char *));
	else if (format == 'p')
		str = ft_convert_ptr((size_t)va_arg(text->args_p, void *), 16, 0);
	else if (format == 'd' || format == 'i')
		str = ft_convert_num((long)va_arg(text->args_p, int), 10, 0);
	else if (format == 'u')
		str = ft_convert_num((long)va_arg(text->args_p, unsigned int), 10, 0);
	else if (format == 'x')
		str = ft_convert_num((long)va_arg(text->args_p, unsigned int), 16, 0);
	else if (format == 'X')
		str = ft_convert_num((long)va_arg(text->args_p, unsigned int), 16, 1);
	else if (format == '%')
		str = ft_chardup('%');
	if (str == NULL)
		str = my_strdup("(null)");
	if (format == 'c')
		ft_join_format(text, str, 1);
	else
		ft_join_format(text, str, ft_strlen(str));
}
