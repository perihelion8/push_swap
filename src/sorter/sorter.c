/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:51:55 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 17:49:31 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_internal.h"

int	ops_sort(int *values, int size)
{
	if (!sorter_bfs(values, size))
		return (0);
	free(values);
	return (1);
}
