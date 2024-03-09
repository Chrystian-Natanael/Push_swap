/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 19:31:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_line(char c)
{
	return (c == 9 || (c >= 11 && c <= 13) || c == ' ');
}

void	create_lst(t_element *new, t_push *push)
{
	push->stacks.stack_a = malloc(sizeof(t_dolist));
	push->stacks.stack_a->first = new;
}
