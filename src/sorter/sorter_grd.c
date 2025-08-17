/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_grd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:20:00 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/16 10:25:47 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_internal.h"

t_arri *sorter_grd(int *values, int size)
{
	t_arri	*keep;

	keep = arri_create_from_array(values, size);
	keep = arri_lcs(keep);
}
