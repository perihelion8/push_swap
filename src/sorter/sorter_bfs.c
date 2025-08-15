/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:55:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/15 07:26:15 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_bfs.h"

static void	bfs_destroy(t_queue *q, t_hashset *h, t_state *s, t_arri *a)
{
	if (q)
		queue_destroy(q, sorter_bfs_state_destroy);
	if (h)
		hashset_destroy(h);
	if (s)
		sorter_bfs_state_destroy(s);
	if (a)
		arri_destroy(a);
}

static t_queue	*bfs_init_queue(int *values, int size, t_hashset *visited)
{
	t_queue	*queue;
	t_state	*state;
	t_arri	*sorted;
	t_uint	i;

	queue = queue_create();
	state = sorter_bfs_state_create(size);
	sorted = arri_create(size);
	if (!queue || !state || !sorted || !queue_enqueue(queue, state))
	{
		bfs_destroy(queue, NULL, state, sorted);
		return (NULL);
	}
	i = 0;
	while (i < state->cap)
		arri_append(sorted, values[i++]);
	arri_sort(sorted);
	i = 0;
	while (i < state->cap)
		arri_append(state->a, arri_index_of(sorted, values[i++]));
	arri_destroy(sorted);
	hashset_insert(visited, sorter_bfs_state_serialize(state));
	return (queue);
}

static int	bfs_check_rule(t_state *state, int rule, t_hashset *visited)
{
	t_ulong	key;
	int		is_visited;

	if (!state)
		return (-1);
	if (sorter_bfs_rules_apply_rule(state, rule))
	{
		key = sorter_bfs_state_serialize(state);
		is_visited = hashset_insert(visited, key);
		if (is_visited != 1)
			sorter_bfs_state_destroy(state);
		return (is_visited);
	}
	return (0);
}

static int	bfs_enqueue_states(t_queue *q, t_state *state, t_hashset *visited)
{
	t_state	*state_copy;
	int		check_return;
	t_uint	i;

	i = 0;
	while (i < 11)
	{
		state_copy = sorter_bfs_state_copy(state);
		check_return = bfs_check_rule(state_copy, i, visited);
		if (check_return == 1)
		{
			arri_append(state_copy->rules, i);
			queue_enqueue(q, state_copy);
		}
		else if (check_return == -1)
			return (0);
		i++;
	}
	return (1);
}

int	sorter_bfs(int *values, int size)
{
	t_queue		*queue;
	t_state		*state;
	t_hashset	*visited;

	visited = hashset_create();
	queue = bfs_init_queue(values, size, visited);
	if (!visited || !queue)
	{
		bfs_destroy(queue, visited, NULL, NULL);
		return (0);
	}
	while (!queue_is_empty(queue))
	{
		state = queue_dequeue(queue);
		if (arri_is_sorted(state->a) && arri_is_empty(state->b))
		{
			sorter_bfs_rules_print(state->rules);
			bfs_destroy(queue, visited, state, NULL);
			return (1);
		}
		bfs_enqueue_states(queue, state, visited);
		sorter_bfs_state_destroy(state);
	}
	return (0);
}
