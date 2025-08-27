/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_rule_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:55:20 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/25 23:26:57 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis_internal.h"

void	sa(t_list *a)
{
	if (list_swap(a))
		putstrln("sa");
}

void	sb(t_list *b)
{
	if (list_swap(b))
		putstrln("sb");
}

void	ss(t_list *a, t_list *b)
{
	int	sa;
	int	sb;

	sa = list_swap(a);
	sb = list_swap(b);
	if (sa && sb)
		putstrln("ss");
	else if (sa)
		putstrln("sa");
	else if (sb)
		putstrln("sb");
}
