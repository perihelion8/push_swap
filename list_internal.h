/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:23:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/30 16:57:02 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_H
# define LIST_INTERNAL_H

# include "types.h"
# include "list.h"

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

t_list_node	*list_node_create(int key);
void		list_node_destroy(t_list_node *node);
t_list_node	*list_pop_front(t_list *lst);

#endif
