/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:08:28 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/14 14:44:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_push *push)
{
	int			min;
	t_element	*tmp;

	if (!push->stacks.stack_a)
		return (-1);
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

int	max_value(t_push *push)
{
	int	max;
	t_element	*tmp;

	if (!push->stacks.stack_a)
		return (-1);
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

int	max_value_b(t_push *push)
{
	int	max;
	t_element	*tmp;

	if (!push->stacks.stack_b || !push->stacks.stack_b->first)
		return (-1);
	tmp = push->stacks.stack_b->first;
	max = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) > max)
		max = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

int	min_value_b(t_push *push)
{
	int			min;
	t_element	*tmp;

	if (!push->stacks.stack_b)
		return (-1);
	tmp = push->stacks.stack_b->first;
	min = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
		min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

void	get_pivots(t_push *push)
{
	push->min_value = min_value(push);
	push->max_value = max_value(push);
	push->big_pivot = (push->min_value + push->max_value) / 2;
	push->small_pivot = (push->min_value + push->big_pivot) / 2;
	push->medium_pivot = (push->small_pivot + push->big_pivot) / 2;
}
