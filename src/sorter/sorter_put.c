/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:06:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/15 22:18:38 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sorter_putstrln(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}
