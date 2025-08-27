/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:36:57 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 17:32:32 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arri_internal.h"

int	arri_push(t_arri *dst, t_arri *src)
{
	int		tmp;
	t_uint	i;

	if (src->len < 1)
		return (0);
	tmp = src->buff[0];
	i = 0;
	while (i < src->len - 1)
	{
		src->buff[i] = src->buff[i + 1];
		i++;
	}
	src->len--;
	i = dst->len;
	while (i > 0)
	{
		dst->buff[i] = dst->buff[i - 1];
		i--;
	}
	dst->buff[0] = tmp;
	dst->len++;
	return (1);
}

int	arri_swap(t_arri *arri)
{
	int	tmp;

	if (arri->len < 2)
		return (0);
	tmp = arri->buff[0];
	arri->buff[0] = arri->buff[1];
	arri->buff[1] = tmp;
	return (1);
}

int	arri_rotate(t_arri *arri)
{
	int		tmp;
	t_uint	i;

	if (arri->len < 2)
		return (0);
	tmp = arri->buff[0];
	i = 0;
	while (i < arri->len - 1)
	{
		arri->buff[i] = arri->buff[i + 1];
		i++;
	}
	arri->buff[arri->len - 1] = tmp;
	return (1);
}

int	arri_rrotate(t_arri *arri)
{
	int		tmp;
	t_uint	i;

	if (arri->len < 2)
		return (0);
	tmp = arri->buff[arri->len - 1];
	i = arri->len - 1;
	while (i > 0)
	{
		arri->buff[i] = arri->buff[i - 1];
		i--;
	}
	arri->buff[0] = tmp;
	return (1);
}
