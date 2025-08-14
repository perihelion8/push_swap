/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:53:20 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 15:34:03 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;

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

#endif
