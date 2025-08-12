/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:30:45 by abazzoun          #+#    #+#             */
/*   Updated: 2025/07/27 18:22:40 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal.h"

int	*parser_arri_alloc(int size)
{
	return ((int *)malloc(sizeof(int) * size));
}

void	parser_arri_free(int *arri)
{
	free(arri);
}
