/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:29:27 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/30 16:51:28 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRI_INTERNAL_H
# define ARRI_INTERNAL_H

# include "arri.h"

struct s_arri
{
	int		*buff;
	t_uint	cap;
	t_uint	len;
};

#endif
