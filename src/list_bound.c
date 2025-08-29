/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:13:42 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 18:13:08 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

static void	list_bound_init(int *bound)
{
	bound[0] = -10;
	bound[1] = 510;
}

static t_uint	list_bound_return(int *bound, t_uint *index)
{
	if (bound[1] == 510)
		return (index[0]);
	return (index[1]);
}

t_uint	list_bound_index(t_list *lst, int key)
{
	t_list_node	*curr;
	int			bound[2];
	t_uint		index[2];
	t_uint		i;

	list_bound_init(bound);
	curr = lst->tail->next;
	i = 0;
	while (i < lst->len)
	{
		if (curr->key < key && curr->key > bound[0])
		{
			bound[0] = curr->key;
			index[0] = i;
		}
		if (curr->key > key && curr->key < bound[1])
		{
			bound[1] = curr->key;
			index[1] = i;
		}
		curr = curr->next;
		i++;
	}
	return (list_bound_return(bound, index));
}
