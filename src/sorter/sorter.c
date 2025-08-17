/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:51:55 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/16 10:08:55 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_internal.h"

int	ops_sort(int *values, int size)
{
	if (size < 6)
		return (sorter_bfs(values, size));
	else
		return (sorter_grd(values, size));
	free(values);
	return (1);
}
