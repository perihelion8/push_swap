/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:14:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 18:24:13 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"
#include "arri.h"
#include "parser.h"
#include "bfs.h"
#include "lis.h"

int	ps_sort(t_arri *arri)
{
	if (arri_len(arri) < 7)
		return (sort_bfs(arri));
	else
		return (sort_lis(arri));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_arri	*arri;

	if (argc < 2)
		return (0);
	arri = parser_args_to_arri(argc, argv);
	if (!arri || !ps_sort(arri))
	{
		puterr();
		return (1);
	}
	return (0);
}
