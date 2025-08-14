/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 06:14:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 15:46:01 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_bfs.h"

t_state	*sorter_bfs_state_create(int cap)
{
	t_state	*state;

	state = malloc(sizeof(*state));
	if (!state)
		return (NULL);
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
