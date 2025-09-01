/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:23:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/01 12:46:12 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_BONUS_H
# define LIST_INTERNAL_BONUS_H

# include "list_bonus.h"

typedef struct s_list_node
{
	int					key;
	struct s_list_node	*prev;
	struct s_list_node	*next;
}	t_list_node;

struct s_list
{
	t_list_node	*tail;
	t_uint		len;
};

void		list_node_destroy(t_list_node *node);
t_list_node	*list_node_create(int key);
t_list_node	*list_pop_front(t_list *lst);

#endif
