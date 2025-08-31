/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:25:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/31 08:48:33 by abazzoun         ###   ########.fr       */
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

int	arri_binary_search(t_arri *sorted, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = sorted->len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (sorted->buff[mid] == value)
			return (mid);
		if (value > sorted->buff[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
