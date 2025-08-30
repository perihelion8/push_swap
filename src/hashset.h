/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:14:49 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/30 15:57:15 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHSET_H
# define HASHSET_H

# include "types.h"

typedef struct s_hashset
{
	t_ulong	*table;
	t_uint	cap;
	t_uint	zero_exists;
}	t_hashset;

t_hashset	*hashset_create(void);
void		hashset_destroy(t_hashset *hashset);
int			hashset_insert(t_hashset *hashset, t_ulong key);

#endif
