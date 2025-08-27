/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:25:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/26 00:43:11 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arri_internal.h"

t_uint	arri_len(t_arri *arri)
{
	return (arri->len);
}

int	arri_get(t_arri *arri, t_uint i)
{
	return (arri->buff[i]);
}

int	arri_index_of(t_arri *arri, int value)
{
	int	i;

	i = 0;
	while ((t_uint)i < arri->len)
	{
		if (arri->buff[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	arri_iterate(t_arri *arri, void (*f)(int))
{
	t_uint	i;

	i = 0;
	while (i < arri->len)
	{
		f(arri->buff[i]);
		i++;
	}
}

int	arri_binary_search(t_arri *sorted_arri, int value)
{
	t_uint	left;
	t_uint	right;
	t_uint	mid;

	left = 0;
	right = sorted_arri->len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arri_get(sorted_arri, mid) == value)
			return (1);
		if (arri_get(sorted_arri, mid) < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}

void	arri_print(t_arri *arri)
{
	t_uint i;

	i = 0;
	while (i < arri->len)
	{
		printf("%d ", arri->buff[i]);
		i++;
	}
	printf("\n");
}
