/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:10:36 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 09:09:03 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_dolist *stk)
{
	int			min;
	t_element	*tmp;

	if (!stk)
		return (-1);
	tmp = stk->first;
	min = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
		min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max_value(t_dolist *stk)
{
	int			max;
	t_element	*tmp;

	if (!stk)
		return (-1);
	tmp = stk->first;
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
	push->min_value = min_value(push->stacks.stack_a);
	push->max_value = max_value(push->stacks.stack_a);
	push->big_pivot = (push->min_value + push->max_value) / 2;
	push->small_pivot = (push->min_value + push->big_pivot) / 2;
}
