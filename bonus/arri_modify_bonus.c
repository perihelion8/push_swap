/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_modify_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:58:38 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/01 12:43:59 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arri_internal_bonus.h"

int	arri_append(t_arri *arri, int n)
{
	if (arri->len == arri->cap)
		return (0);
	arri->buff[arri->len] = n;
	arri->len++;
	return (1);
}

int	arri_prepend(t_arri *arri, int n)
{
	t_uint	i;

	if (arri->len == arri->cap)
		return (0);
	i = arri->len;
	while (i > 0)
	{
		arri->buff[i] = arri->buff[i - 1];
		i--;
	}
	arri->buff[0] = n;
	arri->len++;
	return (1);
}

void	arri_sort(t_arri *arri)
{
	t_uint	i;
	t_uint	j;
	int		tmp;

	i = 0;
	while (i < arri->len - 1)
	{
		j = 0;
		while (j < arri->len - i - 1)
		{
			if (arri->buff[j + 1] < arri->buff[j])
			{
				tmp = arri->buff[j];
				arri->buff[j] = arri->buff[j + 1];
				arri->buff[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
