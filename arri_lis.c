/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:11:56 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/23 10:01:04 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arri_internal.h" 

static void	array_set_all(int *array, t_uint size, int val)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		array[i] = val;
		i++;
	}
}

static t_uint	max_index(int *array, t_uint size)
{
	int		max;
	int		max_index;
	t_uint	i;

	max = array[0];
	max_index = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] > max)
		{
			max = array[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

static t_arri	*form_lis(t_arri *arri, int *l, int *s)
{
	t_arri	*lis;
	t_uint	max_idx;
	int		i;

	max_idx = max_index(l, arri->len);
	lis = arri_with_cap(l[max_idx]);
	if (!lis)
		return (NULL);
	i = max_idx;
	while (i != -1)
	{
		arri_prepend(lis, arri_get(arri, i));
		i = s[i];
	}
	return (lis);
}

t_arri	*arri_lis(t_arri *arri)
{
	int		l[500];
	int		s[500];
	t_uint	i;
	t_uint	j;
	t_arri	*lis;

	array_set_all(l, arri->len, 1);
	array_set_all(s, arri->len, -1);
	i = 0;
	while (i < arri->len)
	{
		j = 0;
		while (j < i)
		{
			if (arri_get(arri, j) < arri_get(arri, i) && l[j] + 1 >= l[i])
			{
				l[i] = l[j] + 1;
				s[i] = j;
			}
			j++;
		}
		i++;
	}
	lis = form_lis(arri, l, s);
	return (lis);
}
