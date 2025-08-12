/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:51:55 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 16:33:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_internal.h"

int	ops_sort(int *values, int size)
{
	t_arri	*arri;
	int		i;

	arri = arri_create(size);
	if (!arri)
		return (0);
	i = 0;
	while (i < size)
	{
		arri->buff[i] = values[i];
		i++;
	}
	arri->len = size;
	if (!arri_is_sorted(arri))
	{
		if (!sorter_bfs(arri))
			return (0);
	}
	arri_destroy(arri);
	free(values);
	return (1);
}
