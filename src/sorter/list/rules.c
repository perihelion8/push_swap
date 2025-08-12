/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:47:25 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 08:41:08 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	list_push(t_list *dst, t_list *src)
{
	t_list_node	*tmp;

	if (src->len > 0)
	{
		tmp = src->head;
		src->head = src->head->next;
		tmp->next = dst->head;
		dst->head = tmp;
		dst->len++;
		src->len--;
		return (1);
	}
	return (0);
}

int	list_swap(t_list *lst)
{
	int	tmp;

	if (lst->len > 1)
	{
		tmp = lst->head->data;
		lst->head->data = lst->head->next->data;
		lst->head->next->data = tmp;
		return (1);
	}
	return (0);
}

int	list_rotate(t_list *lst)
{
	t_list_node	*old_head;

	if (lst->len > 1)
	{
		old_head = lst->head;
		lst->head = old_head->next;
		old_head->next = NULL;
		lst->tail->next = old_head;
		lst->tail = old_head;
		return (1);
	}
	return (0);
}

int	list_reverse_rotate(t_list *lst)
{
	t_list_node	*tail_prev;

	if (lst->len > 1)
	{
		tail_prev = lst->head;
		while (tail_prev->next->next)
			tail_prev = tail_prev->next;
		tail_prev->next = NULL;
		lst->tail->next = lst->head;
		lst->head = lst->tail;
		lst->tail = tail_prev;
		return (1);
	}
	return (0);
}
