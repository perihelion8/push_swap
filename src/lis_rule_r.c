/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_rule_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:44:36 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/24 02:54:39 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis_internal.h"

void	ra(t_list *a)
{
	if (list_rotate(a))
		putstrln("ra");
}

void	rb(t_list *b)
{
	if (list_rotate(b))
		putstrln("rb");
}

void	rr(t_list* a, t_list *b)
{
	int	ra;
	int	rb;

	ra = list_rotate(a);
	rb = list_rotate(b);
	if (ra && rb)
		putstrln("rr");
	else if (ra)
		putstrln("ra");
	else if (rb)
		putstrln("rb");
}
