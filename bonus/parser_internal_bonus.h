/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:03:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/01 12:49:33 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_BONUS_H
# define PARSER_INTERNAL_BONUS_H

# include "parser_bonus.h"

int		parser_validate_input(const char *str);
int		parser_strcmp(const char *s1, const char *s2);
int		parser_atoi(const char *str);

#endif
