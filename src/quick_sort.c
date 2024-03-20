/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:42:18 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 12:12:59 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_prepare(t_push **push)
{
	(*push)->pivot.size = ((*push)->stacks.stack_a->size);
	if ((*push)->stacks.stack_a->size > 200)
		(*push)->pivot.n = 4;
	else
		(*push)->pivot.n = 2;
	if ((*push)->pivot.n >= 4)
	{
		(*push)->pivot.small_pivot = ((*push)->stacks.stack_a->size) \
		/ (*push)->pivot.n;
		(*push)->pivot.big_pivot = ((*push)->stacks.stack_a->size) \
		/ ((*push)->pivot.n / 2);
	}
	else
	{
		(*push)->pivot.small_pivot = ((*push)->stacks.stack_a->size) \
		/ (*push)->pivot.n;
		(*push)->pivot.big_pivot = ((*push)->stacks.stack_a->size) \
		/ ((*push)->pivot.n) + 5;
	}
	sort_partition(push);
}

void	sort_partition(t_push **push)
{
	while ((*push)->stacks.stack_a->size > 5)
	{
		while (count_exist_rank((*push)->stacks.stack_a, \
		(*push)->pivot.big_pivot) && ((*push)->stacks.stack_a->size > 5))
		{
			if ((*push)->stacks.stack_a->first->rank < (*push)->pivot.big_pivot)
				pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
			else
				ra(&(*push)->stacks.stack_a, 1);
		}
		if (count_exist_rank((*push)->stacks.stack_a, \
		(*push)->pivot.big_pivot) == 0)
		{
			(*push)->pivot.small_pivot += ((*push)->pivot.size) \
			/ ((*push)->pivot.n / 2);
			(*push)->pivot.big_pivot += ((*push)->pivot.size) \
			/ ((*push)->pivot.n / 2);
		}
	}
	sort(*push);
	b_to_a(push);
}

void	b_to_a_sort_elements(t_push **push, int size)
{
	while (size != 0)
	{
		calculate_cost(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
		get_cheap_cost(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
		pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
		size--;
	}
}

void	b_to_a(t_push **push)
{
	int	size;

	size = (*push)->stacks.stack_b->size;
	(*push)->pivot.n = 2;
	init_pivots(&(*push)->pivot, size);
	b_to_a_sort_elements(push, size);
	rotate_until_sort((*push)->stacks.stack_a);
}

void	rotate_until_sort(t_dolist *stk_a)
{
	int			min;
	t_element	*tmp;
	int			idx;

	tmp = stk_a->first;
	min = tmp->rank;
	idx = 0;
	while (tmp)
	{
		if (tmp->rank < min)
			min = tmp->rank;
		tmp = tmp->next;
	}
	tmp = stk_a->first;
	while (tmp && tmp->rank != min)
	{
		idx++;
		tmp = tmp->next;
	}
	if (min > ((int)stk_a->size / 2))
		min = min - stk_a->size;
	if (min < 0)
		rra(&stk_a, abs_math(idx));
	else
		ra(&stk_a, abs_math(idx));
}
