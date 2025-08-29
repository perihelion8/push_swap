/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:32:47 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 12:15:42 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis_internal.h"

static int	abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

static int	lis_cost_from_middle(t_list *lst, t_uint index)
{
	t_uint	middle;

	middle = list_len(lst) / 2;
	if (index <= middle)
		return (index);
	else
		return (-1 * (list_len(lst) - index));
}

static int	lis_cost_a(t_list *a, int key)
{
	t_uint	target_index;

	target_index = list_bound_index(a, key);
	return (lis_cost_from_middle(a, target_index));
}

static int	lis_cost_total(int cost_a, int cost_b)
{
	int	min;

	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		cost_a = abs(cost_a);
		cost_b = abs(cost_b);
		min = cost_a;
		if (cost_b < cost_a)
			min = cost_b;
		return (min + abs(cost_a - cost_b));
	}
	return (abs(cost_a) + abs(cost_b));
}

t_cost	lis_cost_min(t_list *a, t_list *b)
{
	t_cost	mincost;
	int		cost[3];
	int		min;
	t_uint	len;
	t_uint	i;

	min = 2000;
	len = list_len(b);
	i = 0;
	while (i < len)
	{
		cost[0] = lis_cost_a(a, list_get_nth(b, i));
		cost[1] = lis_cost_from_middle(b, i);
		cost[2] = lis_cost_total(cost[0], cost[1]);
		if (cost[2] < min)
		{
			min = cost[2];
			mincost.a = cost[0];
			mincost.b = cost[1];
		}
		if (cost[2] == 0)
			break ;
		i++;
	}
	return (mincost);
}
