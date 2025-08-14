/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:25:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 16:26:50 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arri_internal.h"

t_uint	arri_len(t_arri *arri)
{
	return (arri->len);
}

int	arri_get(t_arri *arri, t_uint i)
{
	return (arri->buff[i]);
}

int	arri_index_of(t_arri *arri, int value)
{
	int	i;

	i = 0;
	while ((t_uint)i < arri->len)
	{
		if (arri->buff[i] == value)
			return (i);
		i++;
	}
	return (-1);
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

void	arri_print(t_arri *arri)
{
	t_uint	i;

	i = 0;
	while (i < arri->len - 1)
	{
		printf("%d, ", arri->buff[i]);
		i++;
	}
	printf("%d.\n", arri->buff[i]);
}
