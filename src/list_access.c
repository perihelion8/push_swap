/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 03:02:16 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 12:05:29 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

t_uint	list_len(t_list *lst)
{
	return (lst->len);
}

t_uint	list_index_of(t_list *lst, int key)
{
	t_list_node	*curr;
	t_uint		i;

	curr = lst->tail->next;
	i = 0;
	while (i < lst->len)
	{
		if (curr->key == key)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}

int	list_get_nth(t_list *lst, t_uint index)
{
	t_list_node	*curr;
	t_uint		i;

	curr = lst->tail->next;
	i = 0;
	while (i < index)
	{
		curr = curr->next;
		i++;
	}
	return (curr->key);
}

int	list_get_head(t_list *lst)
{
	return (lst->tail->next->key);
}

int	list_get_tail(t_list *lst)
{
	return (lst->tail->key);
}
