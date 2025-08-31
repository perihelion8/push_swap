/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:47:36 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/30 19:01:22 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "put.h"

void	puterr(void)
{
	write(2, "Error\n", 6);
}

void	put_ok(void)
{
	write(1, "OK\n", 3);
}

void	put_ko(void)
{
	write(1, "KO\n", 3);
}
