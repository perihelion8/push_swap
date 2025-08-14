/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:33:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 18:06:26 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_INTERNAL_H
# define QUEUE_INTERNAL_H

# include "queue.h"

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

t_queue_node	*queue_node_create(void *data);

#endif
