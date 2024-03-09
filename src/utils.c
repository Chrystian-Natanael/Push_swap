/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 11:42:44 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_to_compare(t_push *stack)
{
	int		idx;
	t_stack	*tmp;

	tmp = stack->first_a;
	stack->array = malloc(sizeof(int) * stack->size);
	if (!stack->array)
		return (1);
	idx = 0;
	while (tmp)
	{
		stack->array[idx] = tmp->value;
		tmp = tmp->next;
		idx++;
	}
	return (0);
}
