/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:52:01 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/12 15:10:41 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_SORT_BFS_H
# define SORTER_SORT_BFS_H

#include <stdlib.h>
#include "sorter_internal.h"

typedef struct {
	t_arri	*a;
	t_arri	*b;
	t_arri	*rules;
}	t_state;

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

int		sorter_bfs(t_arri *);
t_state	*sorter_bfs_state_create(int);
void	sorter_bfs_state_destroy(void *);
t_state *sorter_bfs_state_copy(t_state *);
void	sorter_bfs_state_rule_append(t_state *, int);


#endif
