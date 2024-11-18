/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:42:45 by rogiso            #+#    #+#             */
/*   Updated: 2024/05/18 15:42:50 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*my_strjoin(char *str1, char *str2, int is_heep1, int is_heep2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	result = NULL;
	if (str1 && str2 == NULL)
		result = ft_strdup(str1);
	else if (str1 == NULL && str2)
		result = ft_strdup(str2);
	else if (str1 && str2)
	{
		s1_len = ft_strlen(str1);
		s2_len = ft_strlen(str2);
		result = (char *)malloc(s1_len + s2_len + 1);
		if (result != NULL)
		{
			ft_strlcpy(result, str1, s1_len + 1);
			ft_strlcpy(result + s1_len, str2, s2_len + 1);
		}
	}
	if (str1 && is_heep1 == 1)
		free(str1);
	if (str2 && is_heep2 == 1)
		free(str2);
	return (result);
}
