/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:52:01 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/14 20:33:17 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_BFS_H
# define SORTER_BFS_H

# include <stdlib.h>
# include "arri/arri.h"
# include "queue/queue.h"
# include "hashset/hashset.h"
# include "types.h"

typedef struct s_state
{
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

int		sorter_bfs(int *values, int size);
t_state	*sorter_bfs_state_create(int cap);
t_state	*sorter_bfs_state_copy(t_state *state);
t_ulong	sorter_bfs_state_serialize(t_state *state, t_uint cap);
void	sorter_bfs_state_destroy(void *s);
int		sorter_bfs_rules_apply_rule(t_state *state, int rule);
void	sorter_bfs_rules_print(t_arri *rules);
void	sorter_putstrln(const char *str);

#endif
