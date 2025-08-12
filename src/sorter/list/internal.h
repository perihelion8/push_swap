/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:23:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 08:34:17 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

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

typedef struct s_queue_node
{
	void				*data;
	struct s_queue_node	*next;
}	t_queue_node;

struct s_queue
{
	t_queue_node	*head;
	t_queue_node	*tail;
	int				len;
};

t_list_node 	*list_node_create(int data);
t_queue_node	*queue_node_create(void *data);

#endif
