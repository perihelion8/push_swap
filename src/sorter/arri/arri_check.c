/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:50:37 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 17:20:52 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arri_internal.h"

int	arri_is_sorted(t_arri *arri)
{
	t_uint	i;

	if (arri->len == 0)
		return (0);
	i = 1;
	while (i < arri->len)
	{
		if (arri->buff[i] < arri->buff[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	arri_is_empty(t_arri *arri)
{
	if (arri->len == 0)
		return (1);
	return (0);
}
