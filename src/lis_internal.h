/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:55:21 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 11:12:53 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIS_INTERNAL_H
# define LIS_INTERNAL_H

# include "arri.h"
# include "list.h"

typedef struct s_cost
{
	int	a;
	int	b;
}	t_cost;

void	pa(t_list *a, t_list *b);
void	pb(t_list *b, t_list *a);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

void	lis_rotates(t_list *a, t_list *b, t_cost cost);
t_cost	lis_cost_min(t_list *a, t_list *b);

#endif
