/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:55:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/27 23:40:07 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs_internal.h"

static void	bfs_destroy(t_queue *q, t_hashset *h, t_state *s)
{
	if (q)
		queue_destroy(q, bfs_state_destroy);
	if (h)
		hashset_destroy(h);
	if (s)
		bfs_state_destroy(s);
}

static t_queue	*bfs_initial_queue(t_arri *arri, t_hashset *visited)
{
	t_queue	*queue;
	t_state	*state;

	queue = queue_create();
	state = bfs_state_create(arri_len(arri), 20);
	if (!queue || !state || !queue_enqueue(queue, state))
	{
		bfs_destroy(queue, NULL, state);
		return (NULL);
	}
	state->a = arri;
	hashset_insert(visited, state, bfs_state_key);
	return (queue);
}

static int	bfs_node_expansion(t_state *state, t_queue *q, t_hashset *visited)
{
	t_state	*copy;
	t_uint	i;

	i = 0;
	while (i < 11)
	{
		copy = bfs_state_copy(state);
		if (!copy)
			return (0);
		if (bfs_state_apply_rule(copy, i) && hashset_insert(visited, copy, bfs_state_key))
		{
			arri_append(copy->rules, i);
			if (!queue_enqueue(q, copy))
			{
				bfs_state_destroy(copy);
				bfs_destroy(q, visited, state);
				return (0);
			}
		}
		else
			bfs_state_destroy(copy);
		i++;
	}
	bfs_state_destroy(state);
	return (1);
}

int	sort_bfs(t_arri *arri)
{
	t_queue		*q;
	t_hashset	*visited;
	t_state		*state;

	visited = hashset_create();
	q = bfs_initial_queue(arri, visited);
	if (!visited || !q)
	{
		bfs_destroy(q, visited, NULL);
		return (0);
	}
	while (!queue_is_empty(q))
	{
		state = queue_dequeue(q);
		if (arri_is_sorted(state->a) && arri_is_empty(state->b))
		{
			arri_iterate(state->rules, bfs_print_rule);
			bfs_destroy(q, visited, state);
			return (1);
		}
		if (!bfs_node_expansion(state, q, visited))
			return (0);
	}
	return (0);
}
