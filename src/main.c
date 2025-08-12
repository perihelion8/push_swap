/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:14:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/07/27 17:39:35 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "sorter.h"

void	puterr(void)
{
	write(2, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	int	*arri;

	if (argc < 2)
		return (0);
	arri = parser_args_to_arri(argc, argv);
	if (arri == NULL)
	{
		puterr();
		return (1);
	}
	if (ops_sort(arri, argc - 1) == 0)
	{
		puterr();
		return (1);
	}
	return (0);
}
