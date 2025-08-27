/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:29:27 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/28 00:43:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRI_INTERNAL_H
# define ARRI_INTERNAL_H

# include "stdio.h"
# include "arri.h"

struct s_arri
{
	int		*buff;
	t_uint	cap;
	t_uint	len;
};

#endif
