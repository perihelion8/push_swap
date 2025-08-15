/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:15:27 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/15 13:13:04 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hashset_internal.h"

t_hashset	*hashset_create(void)
{
	t_hashset	*hashset;
	t_uint		i;

	hashset = malloc(sizeof(*hashset));
	if (!hashset)
		return (NULL);
	hashset->cap = 600013;
	hashset->table = malloc(hashset->cap * sizeof(t_hash_entry));
	if (!hashset->table)
	{
		free(hashset);
		return (NULL);
	}
	i = 0;
	while (i < hashset->cap)
	{
		hashset->table[i].occupied = 0;
		i++;
	}
	return (hashset);
}

void	hashset_destroy(t_hashset *hashset)
{
	if (hashset)
	{
		if (hashset->table)
			free(hashset->table);
		free(hashset);
	}
}

int	hashset_insert(t_hashset *hashset, t_ulong key)
{
	t_uint	index;
	t_uint	start_index;

	index = key % hashset->cap;
	start_index = index;
	while (hashset->table[index].occupied != 0)
	{
		if (hashset->table[index].key == key)
			return (0);
		index = (index + 1) % hashset->cap;
		if (index == start_index)
			return (-1);
	}
	hashset->table[index].key = key;
	hashset->table[index].occupied = 1;
	return (1);
}
