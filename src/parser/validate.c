/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:47:58 by abazzoun          #+#    #+#             */
/*   Updated: 2025/07/26 18:55:42 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static unsigned int	parser_digits_count(const char *str)
{
	unsigned int	count;

	if (*str == '-')
		str++;
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static int	parser_validate_input_isdigit(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-')
	{
		str++;
		if (*str == '\0')
			return (0);
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static int	parser_validate_input_inrange(const char *str)
{
	unsigned int	digits_count;
	const char		*ref;

	if (*str == '-')
	{
		ref = "2147483648";
		str++;
	}
	else
		ref = "2147483647";
	digits_count = parser_digits_count(str);
	if (digits_count > 10)
		return (0);
	if (digits_count < 10)
		return (1);
	if (parser_strcmp(str, ref) > 0)
		return (0);
	return (1);
}

int	parser_validate_input(const char *str)
{
	if (parser_validate_input_isdigit(str) == 0)
		return (0);
	if (parser_validate_input_inrange(str) == 0)
		return (0);
	return (1);
}
