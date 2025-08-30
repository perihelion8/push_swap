/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:33:50 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/30 16:39:29 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "hashset.h"
#include <stdlib.h>
#include "parser_internal.h"

static t_arri	*parser_ranked_arri(int *values, int size)
{
	t_arri	*ranked;
	t_arri	*sorted;
	int		i;

	ranked = arri_with_cap(size);
	if (!ranked)
		return (NULL);
	sorted = arri_with_val(values, size);
	if (!sorted)
	{
		arri_destroy(ranked);
		return (NULL);
	}
	arri_sort(sorted);
	i = 0;
	while (i < size)
	{
		arri_append(ranked, arri_binary_search(sorted, values[i]));
		i++;
	}
	free(values);
	arri_destroy(sorted);
	return (ranked);
}

static int	parser_assign_value(int *values, int i, char *input, t_hashset *set)
{
	int	value;

	if (!parser_validate_input(input))
		return (0);
	value = parser_atoi(input);
	if (!hashset_insert(set, value))
		return (0);
	values[i] = value;
	return (1);
}

t_arri	*parser_args_to_arri(int argc, char **argv)
{
	t_hashset	*set;
	int			*values;
	int			i;

	values = malloc(sizeof(*values) * (argc - 1));
	if (!values)
		return (NULL);
	set = hashset_create();
	i = 0;
	while (i < argc - 1)
	{
		if (!parser_assign_value(values, i, argv[i + 1], set))
		{
			hashset_destroy(set);
			free(values);
			return (NULL);
		}
		i++;
	}
	hashset_destroy(set);
	return (parser_ranked_arri(values, argc - 1));
}
