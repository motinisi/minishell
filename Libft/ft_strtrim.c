/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:13:46 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/29 12:13:47 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	check_set(const char c, const char *set);

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*result;

	if (str == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	while (str[start] && check_set(str[start], set))
		start++;
	while (start < end && check_set(str[end - 1], set))
		end--;
	size = end - start + 1;
	result = (char *)malloc(size);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &str[start], size);
	return (result);
}

static int	check_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
