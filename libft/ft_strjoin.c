/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:13:31 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/29 12:13:32 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	else if (str2 == NULL)
		return (ft_strdup(str1));
	else if (str1 == NULL)
		return (ft_strdup(str2));
	s1_len = ft_strlen(str1);
	s2_len = ft_strlen(str2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str1, s1_len + 1);
	ft_strlcpy(result + s1_len, str2, s2_len + 1);
	return (result);
}
