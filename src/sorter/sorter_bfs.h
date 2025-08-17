/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_bfs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:52:01 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/16 10:13:14 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_BFS_H
# define SORTER_BFS_H

# include <stdlib.h>

typedef struct s_state
{
	t_uint	cap;
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
t_state	*sorter_bfs_state_create(t_uint cap);
t_state	*sorter_bfs_state_copy(t_state *state);
t_ulong	sorter_bfs_state_serialize(t_state *state);
void	sorter_bfs_state_destroy(void *s);
int		sorter_bfs_rules_apply_rule(t_state *state, int rule);
void	sorter_bfs_rules_print(t_arri *rules);

#endif
