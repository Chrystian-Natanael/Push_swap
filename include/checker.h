/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:37:43 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 11:36:22 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <fcntl.h>

void	free_checker(t_dolist *lst_a, t_dolist *lst_b);
void	mid_parse(t_dolist **a, t_dolist **b);
void	parse_command(t_dolist **a, t_dolist **b, char *command);
void	handle_error(t_dolist **a, t_dolist **b);
void	parse_command_more(t_dolist **a, t_dolist **b, char *command);
int		sort_validation_checker(t_dolist *stack, t_push *push);
int		simple_comp(char *str1, char *str2);

#endif