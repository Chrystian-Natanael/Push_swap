/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:26:06 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 12:07:30 by cnatanae         ###   ########.fr       */
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
	// if (push->stacks.stack_a->size == 5)
	// 	sort_five(push);
	sort_validation(&push->stacks.stack_a, push);
}

void	sort_three(t_push *push)
{
	if (*((int *)push->stacks.stack_a->first->content) == push->max_value)
		ra(&push->stacks.stack_a);
	else if (*((int *)push->stacks.stack_a->first->next->content) == \
	push->max_value)
		rra(&push->stacks.stack_a);
	if (*((int *)push->stacks.stack_a->first->content) > \
	*((int *)push->stacks.stack_a->first->next->content))
		sa(&push->stacks.stack_a);
}

void	sort_four(t_push *push)
{
	if (*(int *)push->stacks.stack_a->first->next->content == push->min_value)
		sa(&push->stacks.stack_a);
	else if (*(int *)push->stacks.stack_a->first->next->next->content == push->min_value)
	{
		ra(&push->stacks.stack_a);
		sa(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->content == push->min_value)
		rra(&push->stacks.stack_a);
	sort_validation(&push->stacks.stack_a, push);
	pb(&push->stacks.stack_a, &push->stacks.stack_b);
	sort_three(push);
	pa(&push->stacks.stack_b, &push->stacks.stack_a);
	printfall(push); // ! APAGAR
}
