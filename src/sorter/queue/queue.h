/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:29:35 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 18:16:38 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

typedef struct s_queue	t_queue;

t_queue	*queue_create(void);
void	*queue_dequeue(t_queue *q);
void	queue_destroy(t_queue *q, void (*data_destroy)(void *));
int		queue_enqueue(t_queue *q, void *data);
int		queue_is_empty(t_queue *q);
int		queue_get_len(t_queue *q);

#endif
