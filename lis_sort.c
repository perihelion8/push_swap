/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:55:55 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 17:56:53 by abazzoun         ###   ########.fr       */
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

static void	lis_init_pushtob(t_list *a, t_list *b, t_arri *keep)
{
	int		pivot;
	t_uint	len;
	t_uint	i;

	len = list_len(a);
	pivot = len / 2;
	i = 0;
	if (arri_len(keep) >= len)
		return ;
	while (i < len)
	{
		if (arri_binary_search(keep, list_get_head(a)) != -1)
			ra(a);
		else if (list_get_head(a) > pivot)
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
	lis_init_pushtob(a, b, keep);
	arri_destroy(arri);
	arri_destroy(keep);
	return (1);
}

static void	lis_final_rotate_a(t_list *a)
{
	t_uint	min_idx;
	t_uint	len;
	t_uint	i;

	min_idx = list_index_of(a, 0);
	len = list_len(a);
	i = 0;
	if (min_idx <= len / 2)
	{
		while (i++ < min_idx)
			ra(a);
	}
	else
	{
		while (i++ < len - min_idx)
			rra(a);
	}
}

int	sort_lis(t_arri *arri)
{
	t_list	*a;
	t_list	*b;
	t_cost	cost;

	a = list_create();
	b = list_create();
	if (!a || !b)
		lis_destroy(a, b);
	lis_init(a, b, arri);
	while (list_len(b) != 0)
	{
		cost = lis_cost_min(a, b);
		lis_rotates(a, b, cost);
		pa(a, b);
		if (list_get_head(a) > list_get_nth(a, 1))
			sa(a);
	}
	lis_final_rotate_a(a);
	lis_destroy(a, b);
	return (1);
}
