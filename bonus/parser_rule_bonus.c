/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:13:13 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/31 08:15:10 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

int	parser_rule(char *str)
{
	if (parser_strcmp(str, "pa\n") == 0)
		return (PA);
	if (parser_strcmp(str, "pb\n") == 0)
		return (PB);
	if (parser_strcmp(str, "sa\n") == 0)
		return (SA);
	if (parser_strcmp(str, "sb\n") == 0)
		return (SB);
	if (parser_strcmp(str, "ss\n") == 0)
		return (SS);
	if (parser_strcmp(str, "ra\n") == 0)
		return (RA);
	if (parser_strcmp(str, "rb\n") == 0)
		return (RB);
	if (parser_strcmp(str, "rr\n") == 0)
		return (RR);
	if (parser_strcmp(str, "rra\n") == 0)
		return (RRA);
	if (parser_strcmp(str, "rrb\n") == 0)
		return (RRB);
	if (parser_strcmp(str, "rrr\n") == 0)
		return (RRR);
	return (RULE_ERR);
}
