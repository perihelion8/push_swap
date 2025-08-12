/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:31:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 12:31:46 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRI_H
# define ARRI_H

#include "types.h"

typedef struct
{
	int		*buff;
	t_uint	cap;
	t_uint	len;
}	t_arri;

t_arri	*arri_create(t_uint);
void	arri_destroy(t_arri *);
int		arri_is_sorted(t_arri *);
t_arri	*arri_copy(t_arri *);
int		arri_rule_push(t_arri *, t_arri *);
int		arri_rule_swap(t_arri *);
int		arri_rule_rotate(t_arri *);
int		arri_rule_reverse_rotate(t_arri *);

#endif
