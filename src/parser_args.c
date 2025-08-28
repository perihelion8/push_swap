/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:33:50 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 02:13:57 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		arri_append(ranked, arri_index_of(sorted, values[i]));
		i++;
	}
	arri_destroy(sorted);
	return (ranked);
}

static int	parser_assign_unique_value(int *arri, char *input, int index)
{
	int	i;
	int	value;

	if (parser_validate_input(input) == 0)
		return (0);
	value = parser_atoi(input);
	i = 0;
	while (i < index)
	{
		if (arri[i] == value)
			return (0);
		i++;
	}
	arri[index] = value;
	return (1);
}

t_arri	*parser_args_to_arri(int argc, char **argv)
{
	t_arri	*arri;
	int		*values;
	int		i;

	values = malloc(sizeof(*values) * (argc - 1));
	if (!values)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (parser_assign_unique_value(values, argv[i + 1], i) == 0)
		{
			free(values);
			return (NULL);
		}
		i++;
	}
	arri = parser_ranked_arri(values, argc - 1);	
	free(values);
	if (!arri)
		return (NULL);
	return (arri);
}
