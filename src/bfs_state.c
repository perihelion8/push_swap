/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 06:14:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 02:04:41 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bfs_internal.h"

t_state	*bfs_state_create(t_uint cap)
{
	t_state	*state;

	state = malloc(sizeof(*state));
	if (!state)
		return (NULL);
	state->cap = cap;
	state->a = arri_with_cap(cap);
	state->b = arri_with_cap(cap);
	state->rules = arri_with_cap(20);
	if (!state->a || !state->b || !state->rules)
	{
		bfs_state_destroy(state);
		return (NULL);
	}
	return (state);
}

t_state	*bfs_state_copy(t_state *state)
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
		bfs_state_destroy(copy);
		return (NULL);
	}
	return (copy);
}

void	bfs_state_destroy(void *s)
{
	t_state	*state;	

	if (!s)
		return ;
	state = s;
	if (state->a)
		arri_destroy(state->a);
	if (state->b)
		arri_destroy(state->b);
	if (state->rules)
		arri_destroy(state->rules);
	free(state);
}

int	bfs_state_apply_rule(t_state *state, int rule)
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

t_ulong	bfs_state_key(void	*s)
{
	t_state	*state;
	t_ulong	key;
	t_uint	i;

	state = s;
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
