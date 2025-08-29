/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:41:57 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/29 12:34:08 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_INTERNAL_H
# define BFS_INTERNAL_H
# include "types.h"
# include "arri.h"
# include "queue.h"

enum e_rule
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

typedef struct s_state
{
	t_uint	cap;
	t_arri	*a;
	t_arri	*b;
	t_arri	*rules;
}	t_state;

typedef struct s_hashset
{
	t_ulong	*table;
	t_uint	cap;
}	t_hashset;

t_state		*bfs_state_create(t_uint cap);
t_state		*bfs_state_copy(t_state *state);
void		bfs_state_destroy(void *s);
int			bfs_state_apply_rule(t_state *state, int rule);
t_ulong		bfs_state_key(t_state *state);
void		bfs_print_rule(int rule);
t_hashset	*hashset_create(void);
void		hashset_destroy(t_hashset *hashset);
int			hashset_insert(t_hashset *hashset, t_ulong key);

#endif
