/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:30:45 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 00:13:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser_internal.h"

int	*parser_arri_alloc(int size)
{
	return ((int *)malloc(sizeof(int) * size));
}

void	parser_arri_free(int *arri)
{
	if (!arri)
		return ;
	free(arri);
}
