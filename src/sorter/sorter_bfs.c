/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:55:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 20:51:22 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_bfs.h"

static t_state	*sorter_bfs_state_init(int *values, int size, t_hashset *hashset)
{
	t_state	*state;
	t_arri	*sorted;
	t_uint	i;

	state = sorter_bfs_state_create(size);
	if (!state)
		return (NULL);
	sorted = arri_create(size);
	if (!sorted)
	{
		sorter_bfs_state_destroy(state);
		return (NULL);
	}
	i = 0;
	while (i < (t_uint)size)
		arri_append(sorted, values[i++]);
	arri_sort(sorted);
	i = 0;
	while (i < (t_uint)size)
		arri_append(state->a, arri_index_of(sorted, values[i++]));
	arri_destroy(sorted);
	arri_print(state->a);
	hashset_insert(hashset, sorter_bfs_state_serialize(state, size));
	return (state);
}

static t_queue	*sorter_bfs_queue_init(int *values, int size, t_hashset *hashset)
{
	t_queue	*queue;
	t_state	*state;

	queue = queue_create();
	if (!queue)
	{
		hashset_destroy(hashset);
		return (NULL);
	}
	state = sorter_bfs_state_init(values, size, hashset);
	if (!state)
	{
		hashset_destroy(hashset);
		queue_destroy(queue, sorter_bfs_state_destroy);
		return (NULL);
	}
	if (!queue_enqueue(queue, state))
	{
		hashset_destroy(hashset);
		sorter_bfs_state_destroy(state);
		queue_destroy(queue, sorter_bfs_state_destroy);
		return (NULL);
	}
	return (queue);
}

static void	sorter_bfs_neighbors_append(t_queue *queue, t_state *state, t_hashset *hashset, t_uint size)
{
	t_state	*state_copy;
	t_uint	i;

	i = 0;
	while (i < 11)
	{
		state_copy = sorter_bfs_state_copy(state);
		if (sorter_bfs_rules_apply_rule(state_copy, i) && hashset_insert(hashset, sorter_bfs_state_serialize(state_copy, size)) == 1)
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
	t_queue		*queue;
	t_state		*state;
	t_hashset	*hashset;

	hashset = hashset_create();
	if (!hashset)
		return (0);
	queue = sorter_bfs_queue_init(values, size, hashset);
	if (!queue)
		return (0);
	printf("ok\n");
	while (!queue_is_empty(queue))
	{
		state = queue_dequeue(queue);
		if (arri_is_sorted(state->a) && arri_is_empty(state->b))
		{
			sorter_bfs_rules_print(state->rules);
			hashset_destroy(hashset);
			sorter_bfs_state_destroy(state);
			queue_destroy(queue, sorter_bfs_state_destroy);
			return (1);
		}
		sorter_bfs_neighbors_append(queue, state, hashset, size);
		sorter_bfs_state_destroy(state);
	}
	return (0);
}
