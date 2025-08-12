/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:20:43 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 15:35:17 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal.h"

t_queue_node	*queue_node_create(void *data)
{
	t_queue_node	*qnode;

	qnode = malloc(sizeof *qnode);
	if (!qnode)
		return (NULL);
	qnode->data = data;
	qnode->next = NULL;
	return (qnode);
}

t_queue	*queue_create(void)
{
	t_queue	*q;

	q = malloc(sizeof *q);
	if (!q)
		return (NULL);
	q->head = NULL;
	q->tail = NULL;
	q->len = 0;
	return (q);
}

void	queue_destroy(t_queue *q, void (*free_data)(void *))
{
	t_queue_node	*old_head;

	if (!q) return ;
	while (q->head)
	{
		old_head = q->head;
		q->head = q->head->next;
		free_data(old_head->data);
		free(old_head);
	}
	free(q);
}

int	queue_enqueue(t_queue *q, void *data)
{
	t_queue_node	*qnode;

	if (!q)
		return (0);
	qnode = queue_node_create(data);
	if (!qnode) return (0);
	if (q->head)
	{
		q->tail->next = qnode;
		q->tail = qnode;
	}
	else
	{
		q->head = qnode;
		q->tail = qnode;
	}
	q->len++;
	return (1);
}

void	*queue_dequeue(t_queue *q)
{
	t_queue_node	*qnode;
	void			*data;

	if (q->head)
	{
		qnode = q->head;
		q->head = q->head->next;
		data = qnode->data;
		q->len--;
		free(qnode);
		return (data);
	}
	return (NULL);
}

int		queue_is_empty(t_queue *q)
{
	if (q->len > 0)
		return (0);
	return (1);
}

int		queue_get_len(t_queue *q)
{
	return (q->len);
}
