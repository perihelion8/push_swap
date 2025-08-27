/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 03:02:16 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/26 00:21:37 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

t_uint	list_len(t_list *lst)
{
	return (lst->len);
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
