/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:48:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/01 12:47:13 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types_bonus.h"
#include "put_bonus.h"
#include "arri_bonus.h"
#include "list_bonus.h"
#include "parser_bonus.h"
#include "get_next_line_bonus.h"

static void	append_to_a(t_list *a, t_arri *arri)
{
	t_uint	len;
	t_uint	i;

	len = arri_len(arri);
	i = 0;
	while (i < len)
	{
		list_append(a, arri_get(arri, i));
		i++;
	}
	arri_destroy(arri);
}

static int	apply_all_input_rules(t_list *a, t_list *b)
{
	enum e_rule	rule;
	char		*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || str[0] == '\n')
			break ;
		rule = parser_rule(str);
		free(str);
		if (rule == RULE_ERR || !list_rules(a, b, rule))
		{
			puterr();
			list_destroy(a);
			list_destroy(b);
			return (0);
		}
	}
	return (1);
}

static void	destroy_lists(t_list *a, t_list *b)
{
	list_destroy(a);
	list_destroy(b);
}

static void	init_lists(t_list **a, t_list **b, t_arri *arri)
{
	*a = list_create();
	*b = list_create();
	append_to_a(*a, arri);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_arri	*arri;

	if (argc < 2)
		return (0);
	arri = parser_args_to_arri(argc, argv);
	if (!arri)
	{
		puterr();
		return (1);
	}
	init_lists(&a, &b, arri);
	if (!apply_all_input_rules(a, b))
	{
		puterr();
		destroy_lists(a, b);
		return (1);
	}
	if (list_is_sorted(a) && list_is_empty(b))
		put_ok();
	else
		put_ko();
	destroy_lists(a, b);
	return (0);
}
