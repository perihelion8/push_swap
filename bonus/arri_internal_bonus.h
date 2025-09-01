/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_internal_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:29:27 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/01 12:43:38 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRI_INTERNAL_BONUS_H
# define ARRI_INTERNAL_BONUS_H

# include "arri_bonus.h"

struct s_arri
{
	int		*buff;
	t_uint	cap;
	t_uint	len;
};

#endif
