/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:17:50 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/07 11:34:23 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal.h"

t_list_node	*list_node_create(int data)
{
	t_list_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->data = data;
	return (node);
}

t_list	*list_create(void)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->len = 0;
	return (lst);
}

void	list_destroy(t_list	*lst)
{
	t_list_node	*previous_head;

	while (lst->head)
	{
		previous_head = lst->head;
		lst->head = lst->head->next;
		free(previous_head);
	}
	free(lst);
}

t_list	*list_create_from_arri(int *arri, int size)
{
	t_list	*lst;
	int		i;

	lst = list_create();
	if (!lst)
	{
		free(arri);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		if (list_prepend(lst, arri[i]) == 0)
		{
			list_destroy(lst);
			free(arri);
			return (NULL);
		}
		i++;
	}
	free(arri);
	return (lst);
}
