/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:32:52 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/16 10:28:09 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arri_internal.h"

t_arri	*arri_create(t_uint cap)
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

void	arri_destroy(t_arri *arri)
{
	if (!arri)
		return ;
	if (arri->buff)
		free(arri->buff);
	free(arri);
}

t_arri	*arri_copy(t_arri *src)
{
	t_arri	*copy;
	t_uint	i;

	copy = arri_create(src->cap);
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

int	arri_append(t_arri *arri, int n)
{
	if (arri->len >= arri->cap)
		return (0);
	arri->buff[arri->len] = n;
	arri->len++;
	return (1);
}
