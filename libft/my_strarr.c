/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:41:36 by rogiso            #+#    #+#             */
/*   Updated: 2024/09/18 22:41:36 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	my_strarr_len(char *str[])
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	**my_strarr_push(char *strs[], char *addstr, int is_heep)
{
	size_t	cnt;
	size_t	len;
	char	**new_strs;

	cnt = 0;
	if (addstr == NULL)
		return (NULL);
	len = my_strarr_len(strs);
	new_strs = (char **)ft_calloc(len + 2, sizeof(char *));
	if (new_strs == NULL)
		return (NULL);
	while (cnt < len)
	{
		new_strs[cnt] = strs[cnt];
		cnt++;
	}
	new_strs[cnt] = ft_strdup(addstr);
	free(strs);
	if (addstr && is_heep == 1)
		free(addstr);
	return (new_strs);
}

void	my_strarr_delete(char *strs[], size_t start, size_t end)
{
	size_t	len;
	size_t	free_end;

	len = my_strarr_len(strs);
	free_end = end;
	if (len < end)
		end = len;
	if (end <= start)
		return ;
	while (end < len)
	{
		if (start < free_end)
			free(strs[start]);
		strs[start] = strs[end];
		start++;
		end++;
	}
	while (start < len)
	{
		if (start < free_end)
			free(strs[start]);
		strs[start] = NULL;
		start++;
	}
}

void	my_strarr_free(char *strs[])
{
	int	cnt;

	cnt = 0;
	while (strs && strs[cnt])
	{
		free(strs[cnt]);
		cnt++;
	}
	free(strs);
}
