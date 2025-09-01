/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:32:52 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/19 14:38:34 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arri_internal.h"

t_arri	*arri_with_cap(t_uint cap)
{
	t_arri	*arri;

	arri = malloc(sizeof(*arri));
	if (!arri)
		return (NULL);
	arri->buff = malloc(cap * sizeof(int));
	if (!arri->buff)
	{
		arri_destroy(arri);
		return (NULL);
	}
	arri->cap = cap;
	arri->len = 0;
	return (arri);
}

t_arri	*arri_with_val(int *values, t_uint size)
{
	t_arri	*arri;
	t_uint	i;

	arri = arri_with_cap(size);
	if (!arri)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arri->buff[i] = values[i];
		i++;
	}
	arri->len = size;
	return (arri);
}

t_arri	*arri_copy(t_arri *src)
{
	t_arri	*copy;
	t_uint	i;

	copy = arri_with_cap(src->cap);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < src->len)
	{
		copy->buff[i] = src->buff[i];
		i++;
	}
	copy->len = src->len;
	return (copy);
}

void	arri_destroy(t_arri *arri)
{
	if (!arri)
		return ;
	if (arri->buff)
		free(arri->buff);
	free(arri);
}
