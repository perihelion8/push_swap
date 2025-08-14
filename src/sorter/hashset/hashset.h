/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:41:33 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 19:20:08 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHSET_H
# define HASHSET_H

# include "types.h"

typedef struct s_hashset	t_hashset;

t_hashset	*hashset_create(void);
void		hashset_destroy(t_hashset *hashset);
int			hashset_insert(t_hashset *hashset, t_ulong key);

#endif
