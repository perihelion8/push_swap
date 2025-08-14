/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:56:01 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 22:18:30 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHSET_INTERNAL_H
# define HASHSET_INTERNAL_H

# include "hashset.h"

typedef struct s_hash_entry
{
	t_ulong	key;
	t_uint	occupied;
}	t_hash_entry;

struct s_hashset
{
	t_hash_entry	*table;
	t_uint			cap;
};

#endif
