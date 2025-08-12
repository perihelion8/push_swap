/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 01:14:29 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 08:42:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	list_is_sorted(t_list *lst)
{
	t_list_node	*curr;
	int			previous;

	curr = lst->head->next;
	previous = lst->head->data;
	while (curr)
	{
		if (previous > curr->data)
			return (0);
		previous = curr->data;
		curr = curr->next;
	}
	return (1);
}

int	list_is_empty(t_list *lst)
{
	if (lst->head)
		return (1);
	return (0);
}
