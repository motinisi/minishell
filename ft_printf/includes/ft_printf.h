/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:25:37 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/06 20:25:38 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# define SIZE 1024

typedef struct s_text
{
	va_list	args_p;
	ssize_t	all_len;
	ssize_t	out_len;
	char	result[SIZE];
}	t_text;

int		ft_printf(const char *format, ...);
char	*ft_convert_num(long num, int base_value, int is_upper);
char	*ft_convert_ptr(size_t num, int base_value, int is_upper);
ssize_t	ft_write_result(t_text *text, ssize_t	len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strdup_safe(const char *str);
char	*ft_chardup(const char str);
char	*ft_substr(const char *str, unsigned int start,	size_t len);
void	ft_join_format(t_text *text, char *addstr, size_t addlen);

#endif
