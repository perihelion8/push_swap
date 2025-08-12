/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:55:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 16:35:00 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_bfs.h"

static int	apply_rule(t_state *state, int rule)
{
	if (rule == PA && arri_rule_push(state->a, state->b))
		return (1);
	if (rule == PB && arri_rule_push(state->b, state->a))
		return (1);
	if (rule == SA && arri_rule_swap(state->a))
		return (1);
	if (rule == SB && arri_rule_swap(state->b))
		return (1);
	if (rule == SS && arri_rule_swap(state->a) && arri_rule_swap(state->b))
		return (1);
	if (rule == RA && arri_rule_rotate(state->a))
		return (1);
	if (rule == RB && arri_rule_rotate(state->b))
		return (1);
	if (rule == RR && arri_rule_rotate(state->a) && arri_rule_rotate(state->b))
		return (1);
	if (rule == RRA && arri_rule_reverse_rotate(state->a))
		return (1);
	if (rule == RRB && arri_rule_reverse_rotate(state->b))
		return (1);
	if (rule == RRR && arri_rule_reverse_rotate(state->a) && arri_rule_reverse_rotate(state->b))
		return (1);
	return (0);
}

static void	sorter_bfs_print(t_arri *rules)
{
	t_uint	i;

	i = 0;
	while (i < rules->len)
	{
		if (rules->buff[i] == PA)
			sorter_putstrln("pa");
		else if (rules->buff[i] == PB)
			sorter_putstrln("pb");
		else if (rules->buff[i] == SA)
			sorter_putstrln("sa");
		else if (rules->buff[i] == SB)
			sorter_putstrln("sb");
		else if (rules->buff[i] == SS)
			sorter_putstrln("ss");
		else if (rules->buff[i] == RA)
			sorter_putstrln("ra");
		else if (rules->buff[i] == RB)
			sorter_putstrln("rb");
		else if (rules->buff[i] == RR)
			sorter_putstrln("rr");
		else if (rules->buff[i] == RRA)
			sorter_putstrln("rra");
		else if (rules->buff[i] == RRB)
			sorter_putstrln("rrb");
		else if (rules->buff[i] == RRR)
			sorter_putstrln("rrr");
		i++;
	}
}

static t_queue	*sorter_bfs_queue_init(t_arri *arri)
{
	t_queue	*queue;
	t_state	*state;
	t_uint	i;

	queue = queue_create();
	if (!queue)
		return (NULL);
	state = sorter_bfs_state_create(arri->cap);
	if (!state)
	{
		queue_destroy(queue, sorter_bfs_state_destroy);
		return (NULL);
	}
	i = 0;
	while (i < arri->len)
	{
		state->a->buff[i] = arri->buff[i];
		i++;
	}
	state->a->len = arri->len;
	if (!queue_enqueue(queue, state))
	{
		sorter_bfs_state_destroy(state);
		queue_destroy(queue, sorter_bfs_state_destroy);
		return (NULL);
	}
	return (queue);
}



int	sorter_bfs(t_arri *arri)
{
	t_queue	*queue;
	t_state	*state;
	t_state	*state_copy;
	t_uint	i;

	queue = sorter_bfs_queue_init(arri);
	if (!queue)
		return (0);
	while (!queue_is_empty(queue))
	{
		state = queue_dequeue(queue);
		if (arri_is_sorted(state->a) && state->b->len == 0)
		{
			sorter_bfs_print(state->rules);
			sorter_bfs_state_destroy(state);
			queue_destroy(queue, sorter_bfs_state_destroy);
			return (1);
		}
		i = 0;
		while (i < 11)
		{
			state_copy = sorter_bfs_state_copy(state);
			if (apply_rule(state_copy, i))
			{
				sorter_bfs_state_rule_append(state_copy, i); 
				queue_enqueue(queue, state_copy); 
			}
			else
				sorter_bfs_state_destroy(state_copy);
			i++;
		}
		sorter_bfs_state_destroy(state);
	}
	queue_destroy(queue, sorter_bfs_state_destroy);
	return (0);
}
