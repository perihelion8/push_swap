/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_rule_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:49:54 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/25 23:28:50 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis_internal.h"

void	rra(t_list *a)
{
	if (list_rrotate(a))
		putstrln("rra");
}

void	rrb(t_list *b)
{
	if (list_rrotate(b))
		putstrln("rrb");
}

void	rrr(t_list *a, t_list *b)
{
	int	rra;
	int	rrb;

	rra = list_rrotate(a);
	rrb = list_rrotate(b);
	if (rra && rrb)
		putstrln("rrr");
	else if (rra)
		putstrln("rra");
	else if (rrb)
		putstrln("rrb");
}
