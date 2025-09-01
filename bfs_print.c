/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:55:56 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 01:50:13 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"
#include "bfs_internal.h"

void	bfs_print_rule(int rule)
{
	if (rule == PA)
		putstrln("pa");
	else if (rule == PB)
		putstrln("pb");
	else if (rule == SA)
		putstrln("sa");
	else if (rule == SB)
		putstrln("sb");
	else if (rule == SS)
		putstrln("ss");
	else if (rule == RA)
		putstrln("ra");
	else if (rule == RB)
		putstrln("rb");
	else if (rule == RR)
		putstrln("rr");
	else if (rule == RRA)
		putstrln("rra");
	else if (rule == RRB)
		putstrln("rrb");
	else if (rule == RRR)
		putstrln("rrr");
}
