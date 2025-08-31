/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:12:34 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/30 16:08:43 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hashset.h"

static t_ulong	hash_ulong(t_ulong key)
{
	return (key * 2654435769UL);
}

t_hashset	*hashset_create(void)
{
	t_hashset	*hashset;
	t_uint		i;

	hashset = malloc(sizeof(*hashset));
	if (!hashset)
		return (NULL);
	hashset->cap = 60013;
	hashset->table = malloc(hashset->cap * sizeof(t_ulong));
	if (!hashset->table)
	{
		free(hashset);
		return (NULL);
	}
	i = 0;
	while (i < hashset->cap)
	{
		hashset->table[i] = 0;
		i++;
	}
	hashset->zero_exists = 0;
	return (hashset);
}

void	hashset_destroy(t_hashset *hashset)
{
	if (!hashset)
		return ;
	if (hashset->table)
		free(hashset->table);
	free(hashset);
}

int	hashset_insert(t_hashset *hashset, t_ulong key)
{
	t_uint	index;
	t_uint	start_index;

	if (key == 0)
	{
		if (hashset->zero_exists)
			return (0);
		hashset->zero_exists = 1;
		return (1);
	}
	index = hash_ulong(key) % hashset->cap;
	start_index = index;
	while (hashset->table[index] != 0)
	{
		if (hashset->table[index] == key)
			return (0);
		index = (index + 1) % hashset->cap;
		if (index == start_index)
			return (-1);
	}
	hashset->table[index] = key;
	return (1);
}
