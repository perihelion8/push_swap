/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:51:55 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 00:22:09 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pssort_internal.h"

int	ps_sort(t_arri *arri)
{
	if (arri_len(arri) <= 6)
		return (sort_bfs(arri));
	else
		return (sort_lis(arri));
	return (1);
}
