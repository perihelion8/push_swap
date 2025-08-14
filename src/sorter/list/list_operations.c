/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:33:21 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 17:37:30 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

int	list_prepend(t_list *lst, int data)
{
	t_list_node	*node;

	node = list_node_create(data);
	if (!node)
		return (0);
	node->next = lst->head;
	lst->head = node;
	if (lst->len == 0)
		lst->tail = node;
	lst->len++;
	return (1);
}

int	list_append(t_list *lst, int data)
{
	t_list_node	*node;

	node = list_node_create(data);
	if (!node)
		return (0);
	if (lst->len == 0)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		lst->tail = node;
	}
	lst->len++;
	return (1);
}

t_list	*list_copy(t_list *lst)
{
	t_list		*copy;
	t_list_node	*curr;

	copy = list_create();
	if (!copy)
		return (NULL);
	curr = lst->head;
	while (curr)
	{
		if (!list_append(copy, curr->data))
		{
			list_destroy(copy);
			return (NULL);
		}
		curr = curr->next;
	}
	return (copy);
}
