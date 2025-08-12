/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:06:34 by abazzoun          #+#    #+#             */
/*   Updated: 2025/07/26 18:51:06 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	parser_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	parser_atoi(const char *str)
{
	int	sign;
	int	n;

	if (parser_strcmp(str, "-2147483648") == 0)
		return (-2147483647 - 1);
	n = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
}
