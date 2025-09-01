/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:33:21 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 12:06:49 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

int	list_prepend(t_list *lst, int key)
{
	t_list_node	*node;
	t_list_node	*head;

	node = list_node_create(key);
	if (!node)
		return (0);
	if (lst->tail == NULL)
	{
		node->next = node;
		node->prev = node;
		lst->tail = node;
	}
	else
	{
		head = lst->tail->next;
		node->next = head;
		node->prev = lst->tail;
		lst->tail->next = node;
		head->prev = node;
	}
	lst->len++;
	return (1);
}

int	list_append(t_list *lst, int key)
{
	t_list_node	*node;
	t_list_node	*head;

	node = list_node_create(key);
	if (!node)
		return (0);
	if (lst->tail == NULL)
	{
		node->prev = node;
		node->next = node;
		lst->tail = node;
	}
	else
	{
		head = lst->tail->next;
		node->next = head;
		node->prev = lst->tail;
		lst->tail->next = node;
		head->prev = node;
		lst->tail = node;
	}
	lst->len++;
	return (1);
}

t_list_node	*list_pop_front(t_list *lst)
{
	t_list_node	*old_head;
	t_list_node	*new_head;

	if (!lst || !lst->tail)
		return (NULL);
	old_head = lst->tail->next;
	if (lst->tail->next == lst->tail)
		lst->tail = NULL;
	else
	{
		new_head = old_head->next;
		new_head->prev = lst->tail;
		lst->tail->next = new_head;
	}
	lst->len--;
	old_head->next = NULL;
	old_head->prev = NULL;
	return (old_head);
}
