/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:53:20 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 15:09:09 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;
typedef struct s_queue	t_queue;

t_list		*list_create(void);
t_list		*list_create_from_arri(int *arri, int size);
t_list		*list_copy(t_list *lst);
void		list_destroy(t_list *lst);
int			list_append(t_list *lst, int data);
int			list_prepend(t_list *lst, int data);
int			list_is_sorted(t_list *lst);
int			list_is_empty(t_list *lst);
int			list_push(t_list *dst, t_list *src);
int			list_swap(t_list *lst);
int			list_rotate(t_list *lst);
int			list_reverse_rotate(t_list *lst);

t_queue		*queue_create(void);
void		queue_destroy(t_queue *, void(*)(void *));
int			queue_enqueue(t_queue *q, void *data);
void		*queue_dequeue(t_queue *q);
int			queue_is_empty(t_queue *);
int			queue_get_len(t_queue *);

#endif
