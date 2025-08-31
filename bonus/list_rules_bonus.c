/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:47:25 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/31 08:21:40 by abazzoun         ###   ########.fr       */
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

int	list_rules(t_list *a, t_list *b, enum e_rule rule)
{
	if (rule == PA)
		return (list_push(a, b));
	if (rule == PB)
		return (list_push(b, a));
	if (rule == SA)
		return (list_swap(a));
	if (rule == SB)
		return (list_swap(b));
	if (rule == RA)
		return (list_rotate(a));
	if (rule == RB)
		return (list_rotate(b));
	if (rule == RRA)
		return (list_rrotate(a));
	if (rule == RRB)
		return (list_rrotate(b));
	return (0);
}
