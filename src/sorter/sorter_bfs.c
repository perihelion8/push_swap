/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:55:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 11:52:32 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_bfs.h"

static t_queue	*sorter_bfs_queue_init(int *values, int size)
{
	t_queue	*queue;
	t_state	*state;
	t_uint	i;

	queue = queue_create();
	if (!queue)
		return (NULL);
	state = sorter_bfs_state_create(size);
	if (!state)
	{
		queue_destroy(queue, sorter_bfs_state_destroy);
		return (NULL);
	}
	i = 0;
	while (i < (t_uint)size)
		arri_append(state->a, values[i++]);
	if (!queue_enqueue(queue, state))
	{
		sorter_bfs_state_destroy(state);
		queue_destroy(queue, sorter_bfs_state_destroy);
		return (NULL);
	}
	return (queue);
}

static void	sorter_bfs_neighbors_append(t_queue *queue, t_state *state)
{
	t_state	*state_copy;
	t_uint	i;

	i = 0;
	while (i < 11)
	{
		state_copy = sorter_bfs_state_copy(state);
		if (sorter_bfs_rules_apply_rule(state_copy, i))
		{
			arri_append(state_copy->rules, i);
			queue_enqueue(queue, state_copy);
		}
		else
			sorter_bfs_state_destroy(state_copy);
		i++;
	}
}

int	sorter_bfs(int *values, int size)
{
	t_queue	*queue;
	t_state	*state;

	queue = sorter_bfs_queue_init(values, size);
	if (!queue)
		return (0);
	while (!queue_is_empty(queue))
	{
		state = queue_dequeue(queue);
		if (arri_is_sorted(state->a) && arri_is_empty(state->b))
		{
			sorter_bfs_rules_print(state->rules);
			sorter_bfs_state_destroy(state);
			queue_destroy(queue, sorter_bfs_state_destroy);
			return (1);
		}
		sorter_bfs_neighbors_append(queue, state);
		sorter_bfs_state_destroy(state);
	}
	queue_destroy(queue, sorter_bfs_state_destroy);
	return (0);
}
