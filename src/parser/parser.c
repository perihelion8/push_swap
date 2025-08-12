/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:33:50 by abazzoun          #+#    #+#             */
/*   Updated: 2025/07/27 18:23:58 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	parser_assign_unique_value(int *arri, char *input, int index)
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

int	*parser_args_to_arri(int argc, char **argv)
{
	int	*arri;
	int	i;

	arri = parser_arri_alloc(argc - 1);
	if (!arri)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (parser_assign_unique_value(arri, argv[argc - 1 - i], i) == 0)
		{
			parser_arri_free(arri);
			return (NULL);
		}
		i++;
	}
	return (arri);
}
