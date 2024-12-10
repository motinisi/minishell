/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:13:03 by rogiso            #+#    #+#             */
/*   Updated: 2024/09/17 15:13:04 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_slice	*my_slice_create(size_t size, size_t capacity, int is_heep)
{
	t_slice	*slice;

	slice = (t_slice *)malloc(sizeof(t_slice));
	if (slice == NULL)
		return (NULL);
	slice->data = ft_calloc(capacity + 1, size);
	if (slice->data == NULL)
	{
		free(slice);
		return (NULL);
	}
	slice->size = size;
	slice->length = 0;
	slice->capacity = capacity;
	slice->is_heep = is_heep;
	slice->is_error = 0;
	return (slice);
}

void	my_slice_append(t_slice *slice, void *elem)
{
	void	*new_data;

	if (slice == NULL)
		return ;
	if (slice->capacity <= slice->length)
	{
		if (slice->capacity < 1024)
			slice->capacity *= 2;
		else
			slice->capacity += 1024;
		new_data = ft_calloc(slice->capacity + 1, slice->size);
		if (new_data == NULL)
		{
			slice->is_error = 1;
			return ;
		}
		ft_memcpy(new_data, slice->data, slice->length * slice->size);
		free(slice->data);
		slice->data = new_data;
	}
	ft_memcpy(slice->data + (slice->length * slice->size), elem, slice->size);
	slice->length++;
}

void	my_slice_delete(t_slice *slice, size_t start, size_t end)
{
	size_t	cnt;
	void	*start_data;
	void	*end_data;

	if (slice == NULL)
		return ;
	if (slice->length < end)
		end = slice->length;
	if (end <= start)
		return ;
	if (slice->is_heep)
	{
		cnt = start;
		while (cnt < end)
		{
			free(*(void **)(slice->data + (cnt * slice->size)));
			cnt++;
		}
	}
	start_data = slice->data + (start * slice->size);
	end_data = slice->data + (end * slice->size);
	ft_memmove(start_data, end_data, (slice->length - end) * slice->size);
	end_data = slice->data + ((slice->length - (end - start)) * slice->size);
	ft_memset(end_data, 0, (end - start) * slice->size);
	slice->length = slice->length - (end - start);
}

void	my_slice_free(t_slice **slice)
{
	size_t	cnt;

	cnt = 0;
	if (slice == NULL || *slice == NULL)
		return ;
	if ((*slice)->is_heep && (*slice)->data)
	{
		while (cnt < (*slice)->length)
		{
			free(*(void **)((*slice)->data + (cnt * (*slice)->size)));
			cnt++;
		}
	}
	free((*slice)->data);
	free(*slice);
	*slice = NULL;
}
