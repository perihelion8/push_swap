/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:25:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/13 18:01:38 by abazzoun         ###   ########.fr       */
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
