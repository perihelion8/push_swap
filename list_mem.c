/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:17:50 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/24 00:12:17 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list_internal.h"

t_list_node	*list_node_create(int key)
{
	t_list_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->key = key;
	return (node);
}

void	list_node_destroy(t_list_node *node)
{
	if (!node)
		return ;
	free(node);
}

t_list	*list_create(void)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->tail = NULL;
	lst->len = 0;
	return (lst);
}

void	list_destroy(t_list	*lst)
{
	t_list_node	*tmp;
	t_uint		i;

	if (!lst)
		return ;
	i = 0;
	while (i < lst->len)
	{
		tmp = lst->tail;
		lst->tail = lst->tail->prev;
		free(tmp);
		i++;
	}
	free(lst);
}
