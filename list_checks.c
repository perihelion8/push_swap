/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 01:14:29 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/31 08:37:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

int	list_is_sorted(t_list *lst)
{
	t_list_node	*curr;
	t_uint		i;

	curr = lst->tail->next;
	i = 1;
	while (i < lst->len)
	{
		if (curr->key > curr->next->key)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	list_is_empty(t_list *lst)
{
	if (lst->tail)
		return (0);
	return (1);
}
