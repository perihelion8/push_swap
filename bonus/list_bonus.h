/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:53:20 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/31 08:52:02 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;

t_list	*list_create(void);
void	list_destroy(t_list *lst);
int		list_append(t_list *lst, int key);
int		list_prepend(t_list *lst, int kye);
int		list_is_sorted(t_list *lst);
int		list_is_empty(t_list *lst);
t_uint	list_len(t_list *lst);
int		list_push(t_list *dst, t_list *src);
int		list_swap(t_list *lst);
int		list_rotate(t_list *lst);
int		list_rrotate(t_list *lst);
int		list_rules(t_list *a, t_list *b, enum e_rule rule);

#endif
