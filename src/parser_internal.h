/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:03:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/08/27 23:13:23 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include <stddef.h>
# include "parser.h"

int		parser_validate_input(const char *str);
int		parser_strcmp(const char *s1, const char *s2);
int		parser_atoi(const char *str);
int		*parser_arri_alloc(int size);
void	parser_arri_free(int *arri);

#endif
