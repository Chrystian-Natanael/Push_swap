/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:36:44 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 09:09:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push *push)
{
	if (!sort_validation(&push->stacks.stack_a, push))
	{
		get_pivots(push);
		if (push->stacks.stack_a->size == 2)
			sa(&push->stacks.stack_a, 1);
		else if (push->stacks.stack_a->size == 3)
			sort_three(push->stacks.stack_a);
		else if (push->stacks.stack_a->size == 4)
			sort_four(push->stacks.stack_a, push->stacks.stack_b, push);
		else if (push->stacks.stack_a->size == 5)
			sort_five(push->stacks.stack_a, push->stacks.stack_b, push);
		else
			sort_prepare(&push);
	}
}

void	sort_three(t_dolist *stk)
{
	int	max;

	max = max_value(stk);
	if (*((int *)stk->first->content) == max)
		ra(&stk, 1);
	else if (*((int *)stk->first->next->content) == \
	max)
		rra(&stk, 1);
	if (*((int *)stk->first->content) > \
	*((int *)stk->first->next->content))
		sa(&stk, 1);
}

void	sort_four(t_dolist *stk_a, t_dolist *stk_b, t_push *push)
{
	int	min;

	min = min_value(stk_a);
	if (*(int *)stk_a->first->next->content == min)
		sa(&stk_a, 1);
	else if (*(int *)stk_a->first->next->next->content == min)
	{
		ra(&stk_a, 1);
		sa(&stk_a, 1);
	}
	else if (*(int *)stk_a->first->next->next->next->content == min)
		rra(&stk_a, 1);
	if (!sort_validation(&stk_a, push))
	{
		pb(&stk_a, &stk_b, 1);
		sort_three(stk_a);
		pa(&stk_b, &stk_a, 1);
	}
	else
		sort_three(stk_a);
}

void	sort_five(t_dolist *stk_a, t_dolist *stk_b, t_push *push)
{
	int	min;

	min = min_value(stk_a);
	if (*(int *)stk_a->first->next->content == min)
		sa(&stk_a, 1);
	else if (*(int *)stk_a->first->next->next->content == min)
		rra(&stk_a, 3);
	else if (*(int *)stk_a->first->next->next->next->content == min)
		rra(&stk_a, 2);
	else if (*(int *)stk_a->first->next->next->next->next->content == min)
		rra(&stk_a, 1);
	if (!sort_validation(&stk_a, push))
	{
		pb(&stk_a, &stk_b, 1);
		sort_four(stk_a, stk_b, push);
		pa(&stk_b, &stk_a, 1);
	}
	else
		sort_four(stk_a, stk_b, push);
}

void	sort_three_rank(t_dolist *stk)
{
	int	first;
	int	second;
	int	third;

	first = value(stk, 1);
	second = value(stk, 2);
	third = value(stk, 3);
	if (first > second && third > second && third > first)
		sa(&stk, 1);
	else if (first > second && third > second && first > third)
		ra(&stk, 1);
	else if (second > first && second > third && first > third)
		rra(&stk, 1);
	else if (second > first && second > third && third > first)
	{
		sa(&stk, 1);
		ra(&stk, 1);
	}
	else if (first > second && second > third && first > third)
	{
		sa(&stk, 1);
		rra(&stk, 1);
	}
}
