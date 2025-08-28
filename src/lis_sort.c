/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:55:55 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 11:06:25 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis_internal.h"

static void	lis_destroy(t_list *a, t_list *b)
{
	if (a)
		list_destroy(a);
	if (b)
		list_destroy(b);
}

static int	abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

static void	lis_init_pushtob(t_list *a, t_list *b, t_arri *keep)
{
	int		pivot;
	t_uint	len;
	t_uint	i;

	len = list_len(a);
	pivot = len / 2;
	i = 0;
	while (i< len)
	{
		if (arri_index_of(keep, list_get_head(a)) != -1)
			ra(a);
		else if (list_get_nth(a, 0) > pivot)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
		i++;	
	}
}

static int	lis_init(t_list *a, t_list *b, t_arri *arri)
{
	t_arri	*keep;
	t_uint	len;
	t_uint	i;

	len = arri_len(arri);
	i = 0;
	while (i < len)
	{
		list_append(a, arri_get(arri, i));
		i++;
	}
	keep = arri_lis(arri);
	arri_sort(arri);
	lis_init_pushtob(a, b, keep);
	arri_destroy(arri);
	arri_destroy(keep);
	return (1);
}

static t_uint	lis_min_cost_index(t_list *a, t_list *b)
{
	int		cost_b;
	int		cost_a;
	int		min;
	t_uint	minindex;
	t_uint	len;
	t_uint	i;

	min = 500;
	minindex = 0;
	len = list_len(b);
	i = 0;
	while (i < len)
	{
		cost_b = abs(lis_cost_b(b, i));
		cost_a = abs(lis_cost_a(a, list_get_nth(b, i)));
		if (cost_a + cost_b < min)
		{
			min = cost_a + cost_b;
			minindex = i;
		}
		i++;
	}
	return (minindex);
}

int	sort_lis(t_arri *arri)
{
	t_list	*a;
	t_list	*b;
	t_uint	mincost_index;
	int		cost_a;
	int		cost_b;

	a = list_create();
	b = list_create();
	if (!a || !b)
		lis_destroy(a, b);
	lis_init(a, b, arri);
	while (list_len(b) != 0)
	{
		mincost_index = lis_min_cost_index(a, b);
		cost_b = lis_cost_b(b, mincost_index);
		cost_a = lis_cost_a(a, list_get_nth(b, mincost_index));
		lis_rotates(a, b, cost_a, cost_b);
		pa(a, b);
		if (list_get_head(a) > list_get_nth(a, 1))
			sa(a);
	}
	while (list_get_head(a) > list_get_tail(a))
		ra(a);
	lis_destroy(a, b);
	return (1);
}
