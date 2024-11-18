/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:36:31 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/29 18:36:32 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	int		cnt;
	size_t	len;
	char	*result;

	if (str == NULL || f == NULL)
		return (NULL);
	cnt = 0;
	len = ft_strlen(str);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (str[cnt])
	{
		result[cnt] = f(cnt, str[cnt]);
		cnt++;
	}
	result[cnt] = '\0';
	return (result);
}
