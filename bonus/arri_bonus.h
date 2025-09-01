/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:31:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/01 12:43:27 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRI_BONUS_H
# define ARRI_BONUS_H

# include "types_bonus.h"

typedef struct s_arri	t_arri;

t_arri	*arri_with_cap(t_uint cap);
t_arri	*arri_with_val(int *values, t_uint size);
t_uint	arri_len(t_arri *arri);
void	arri_destroy(t_arri *arri);
void	arri_sort(t_arri *arri);
int		arri_append(t_arri *arri, int n);
int		arri_get(t_arri *arri, t_uint i);
int		arri_binary_search(t_arri *sorted_arri, int value);

#endif
