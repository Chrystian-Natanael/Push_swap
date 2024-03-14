/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:26:06 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 18:26:02 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push *push)
{
	sort_validation(&push->stacks.stack_a, push);
	get_pivots(push);
	if (push->stacks.stack_a->size == 2)
		sa(&push->stacks.stack_a);
	else if (push->stacks.stack_a->size == 3)
		sort_three(push);
	else if (push->stacks.stack_a->size == 4)
		sort_four(push);
	else if (push->stacks.stack_a->size == 5)
		sort_five(push);
	else
		quick_sort(&push);
	sort_validation(&push->stacks.stack_a, push);
}

void	sort_three(t_push *push)
{
	int	max;

	max = max_value(push);
	if (*((int *)push->stacks.stack_a->first->content) == max)
		ra(&push->stacks.stack_a);
	else if (*((int *)push->stacks.stack_a->first->next->content) == \
	max)
		rra(&push->stacks.stack_a);
	if (*((int *)push->stacks.stack_a->first->content) > \
	*((int *)push->stacks.stack_a->first->next->content))
		sa(&push->stacks.stack_a);
}

void	sort_four(t_push *push)
{
	int	min;

	min = min_value(push);
	if (*(int *)push->stacks.stack_a->first->next->content == min)
		sa(&push->stacks.stack_a);
	else if (*(int *)push->stacks.stack_a->first->next->next->content == min)
	{
		ra(&push->stacks.stack_a);
		sa(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->content == min)
		rra(&push->stacks.stack_a);
	if (!sort_validation(&push->stacks.stack_a, push))
	{
		pb(&push->stacks.stack_a, &push->stacks.stack_b);
		sort_three(push);
		pa(&push->stacks.stack_b, &push->stacks.stack_a);
	}
	else
		sort_three(push);
}

void	sort_five(t_push *push)
{
	int	min;

	min = min_value(push);
	if (*(int *)push->stacks.stack_a->first->next->content == min)
		sa(&push->stacks.stack_a);
	else if (*(int *)push->stacks.stack_a->first->next->next->content == min)
	{
		rra(&push->stacks.stack_a);
		rra(&push->stacks.stack_a);
		rra(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->content == min)
	{
		rra(&push->stacks.stack_a);
		rra(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->next->content == min)
		rra(&push->stacks.stack_a);
	if (!sort_validation(&push->stacks.stack_a, push))
	{
		pb(&push->stacks.stack_a, &push->stacks.stack_b);
		sort_four(push);
		pa(&push->stacks.stack_b, &push->stacks.stack_a);
	}
	else
		sort_four(push);
}
