/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:32:47 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/26 15:03:38 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lis_internal.h"

static int	lis_cost_from_middle(t_list *lst, t_uint index)
{
	t_uint	middle;

	middle = list_len(lst) / 2;
	if (index <= middle)
		return (index);
	else
		return (-1 * (list_len(lst) - index));
}

static int	lis_cost_superior_index(t_list *a, int key)
{
	int		key_i;
	int		inferior;
	t_uint	inferior_index;
	t_uint	len;
	t_uint	i;

	inferior = 100000;
	inferior_index = -1;
	len = list_len(a);
	i = 0;
	while (i < len)
	{
		key_i = list_get_nth(a, i);
		if (key_i > key && key_i < inferior)
		{
			inferior = key_i;
			inferior_index = i;
		}
		i++;	
	}
	return (inferior_index);
}

static int	lis_cost_inferior_index(t_list *a, int key)
{
	int		key_i;
	int		inferior;
	t_uint	inferior_index;
	t_uint	len;
	t_uint	i;

	inferior = -100000;
	inferior_index = -1;
	len = list_len(a);
	i = 0;
	while (i < len)
	{
		key_i = list_get_nth(a, i);
		if (key_i < key && key_i > inferior)
		{
			inferior = key_i;
			inferior_index = i;
		}
		i++;	
	}
	return (inferior_index);
}

int	lis_cost_a(t_list *a, int key)
{
	int	key_cost;
	int	target_index;

	target_index = lis_cost_superior_index(a, key);
	if (target_index == -1)
		target_index = lis_cost_inferior_index(a, key);
	key_cost = lis_cost_from_middle(a, target_index);
	return (key_cost);
}

int	lis_cost_b(t_list *b, t_uint index)
{
	return (lis_cost_from_middle(b, index));
}
