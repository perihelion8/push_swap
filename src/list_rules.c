/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:47:25 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/26 00:35:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

int	list_push(t_list *dst, t_list *src)
{
	t_list_node	*tmp;

	if (list_len(src) == 0)
		return (0);
	
	tmp = list_pop_front(src);
	list_prepend(dst, tmp->key);
	list_node_destroy(tmp);
	return (1);
}

int	list_swap(t_list *lst)
{
	int	tmp;

	if (lst->len <= 1)
		return (0);
	tmp = lst->tail->next->key;
	lst->tail->next->key = lst->tail->next->next->key;
	lst->tail->next->next->key = tmp;
	return (1);
}

int	list_rotate(t_list *lst)
{
	if (lst->len <= 1)
		return (0);
	lst->tail = lst->tail->next;
	return (1);
}

int	list_rrotate(t_list *lst)
{
	if (lst->len <= 1)
		return (0);
	lst->tail = lst->tail->prev;
	return (1);
}
