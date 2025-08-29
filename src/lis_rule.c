/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_rule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:52:14 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 11:34:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis_internal.h"

static void	lis_rotates_a(t_list *a, int cost_a)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
}

static void	lis_rotates_b(t_list *b, int cost_b)
{
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

void	lis_rotates(t_list *a, t_list *b, t_cost cost)
{
	while (cost.a > 0 && cost.b > 0)
	{
		rr(a, b);
		cost.a--;
		cost.b--;
	}
	while (cost.a < 0 && cost.b < 0)
	{
		rrr(a, b);
		cost.a++;
		cost.b++;
	}
	lis_rotates_a(a, cost.a);
	lis_rotates_b(b, cost.b);
}
