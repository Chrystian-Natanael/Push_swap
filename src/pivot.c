/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:08:28 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 10:38:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pivots(t_push *push)
{
	int			min;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	min = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
		min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max_pivots(t_push *push)
{
	int	max;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	max = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) > max)
		max = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

void	get_pivots(t_push *push)
{
	push->min_value = min_pivots(push);
	push->max_value = max_pivots(push);
	push->big_pivot = (push->min_value + push->max_value) / 2;
	push->small_pivot = (push->min_value + push->big_pivot) / 2;
}
