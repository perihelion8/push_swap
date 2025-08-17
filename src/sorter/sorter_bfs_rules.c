/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs_rules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:55:56 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/15 22:17:38 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_internal.h"

static void	print_rule(int rule)
{
	if (rule == PA)
		sorter_putstrln("pa");
	else if (rule == PB)
		sorter_putstrln("pb");
	else if (rule == SA)
		sorter_putstrln("sa");
	else if (rule == SB)
		sorter_putstrln("sb");
	else if (rule == SS)
		sorter_putstrln("ss");
	else if (rule == RA)
		sorter_putstrln("ra");
	else if (rule == RB)
		sorter_putstrln("rb");
	else if (rule == RR)
		sorter_putstrln("rr");
	else if (rule == RRA)
		sorter_putstrln("rra");
	else if (rule == RRB)
		sorter_putstrln("rrb");
	else if (rule == RRR)
		sorter_putstrln("rrr");
}

int	sorter_bfs_rules_apply_rule(t_state *state, int rule)
{
	if (rule == PA && arri_push(state->a, state->b))
		return (1);
	if (rule == PB && arri_push(state->b, state->a))
		return (1);
	if (rule == SA && arri_swap(state->a))
		return (1);
	if (rule == SB && arri_swap(state->b))
		return (1);
	if (rule == SS && arri_swap(state->a) && arri_swap(state->b))
		return (1);
	if (rule == RA && arri_rotate(state->a))
		return (1);
	if (rule == RB && arri_rotate(state->b))
		return (1);
	if (rule == RR && arri_rotate(state->a) && arri_rotate(state->b))
		return (1);
	if (rule == RRA && arri_rrotate(state->a))
		return (1);
	if (rule == RRB && arri_rrotate(state->b))
		return (1);
	if (rule == RRR && arri_rrotate(state->a) && arri_rrotate(state->b))
		return (1);
	return (0);
}

void	sorter_bfs_rules_print(t_arri *rules)
{
	t_uint	i;

	i = 0;
	while (i < arri_len(rules))
	{
		print_rule(arri_get(rules, i));
		i++;
	}
}
