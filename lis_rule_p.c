/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_rule_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:37:36 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 01:51:24 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"
#include "lis_internal.h"

void	pa(t_list *a, t_list *b)
{
	if (list_push(a, b))
		putstrln("pa");
}

void	pb(t_list *a, t_list *b)
{
	if (list_push(b, a))
		putstrln("pb");
}
