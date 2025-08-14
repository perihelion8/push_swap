/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:23:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 17:36:42 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_H
# define LIST_INTERNAL_H

# include <stddef.h>
# include "list.h"

typedef struct s_list_node
{
	int					data;
	struct s_list_node	*next;
}	t_list_node;

struct s_list
{
	t_list_node	*head;
	t_list_node	*tail;
	int			len;
};

t_list_node		*list_node_create(int data);

#endif
