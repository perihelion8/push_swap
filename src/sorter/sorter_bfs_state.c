/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 06:14:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/15 00:58:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_bfs.h"

t_state	*sorter_bfs_state_create(t_uint cap)
{
	t_state	*state;

	state = malloc(sizeof(*state));
	if (!state)
		return (NULL);
	state->cap = cap;
	state->a = arri_create(cap);
	state->b = arri_create(cap);
	state->rules = arri_create(50);
	if (!state->a || !state->b || !state->rules)
	{
		sorter_bfs_state_destroy(state);
		return (NULL);
	}
	return (state);
}

void	sorter_bfs_state_destroy(void *s)
{
	t_state	*state;	

	if (s)
	{
		state = s;
		if (state->a)
			arri_destroy(state->a);
		if (state->b)
			arri_destroy(state->b);
		if (state->rules)
			arri_destroy(state->rules);
		free(state);
	}
}

t_state	*sorter_bfs_state_copy(t_state *state)
{
	t_state	*copy;

	copy = malloc(sizeof(*copy));
	if (!state)
		return (NULL);
	copy->cap = state->cap;
	copy->a = arri_copy(state->a);
	copy->b = arri_copy(state->b);
	copy->rules = arri_copy(state->rules);
	if (!copy->a || !copy->b || !copy->rules)
	{
		sorter_bfs_state_destroy(state);
		return (NULL);
	}
	return (copy);
}

t_ulong	sorter_bfs_state_serialize(t_state *state)
{
	t_ulong	key;
	t_uint	i;

	key = 0;
	i = 0;
	while (i < state->cap)
	{
		if (i < arri_len(state->a))
			key = key * (state->cap + 1) + arri_get(state->a, i);
		else
			key += key * (state->cap + 1) + state->cap;
		i++;
	}
	i = 0;
	while (i < state->cap)
	{
		if (i < arri_len(state->b))
			key = key * (state->cap + 1) + arri_get(state->b, i);
		else
			key = key * (state->cap + 1) + state->cap;
		i++;
	}
	return (key);
}
