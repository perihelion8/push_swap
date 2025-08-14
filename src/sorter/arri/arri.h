/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arri.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:31:15 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 16:24:56 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRI_H
# define ARRI_H

# include "types.h"

typedef struct s_arri	t_arri;

t_arri	*arri_create(t_uint cap);
t_arri	*arri_copy(t_arri *src);
t_uint	arri_len(t_arri *arri);
void	arri_print(t_arri *arri);
void	arri_destroy(t_arri *arri);
void	arri_sort(t_arri *arri);
int		arri_append(t_arri *arri, int n);
int		arri_index_of(t_arri *arri, int value);
int		arri_get(t_arri *arri, t_uint i);
int		arri_is_empty(t_arri *arri);
int		arri_is_sorted(t_arri *arri);
int		arri_push(t_arri *dst, t_arri *src);
int		arri_swap(t_arri *arri);
int		arri_rotate(t_arri *arri);
int		arri_rrotate(t_arri *arri);

#endif
