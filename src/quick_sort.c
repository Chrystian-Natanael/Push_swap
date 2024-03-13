/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:20:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 16:49:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_push **push)
{
	int	iterations;

	iterations = (*push)->stacks.stack_a->size;
	while (iterations--)
	{
		if (CONTENT_A < (*push)->big_pivot)
		{
			pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
			if (SIZE_B > 1 && (CONTENT_B) < (*push)->small_pivot)
			{
				if (CONTENT_A > (*push)->big_pivot)
					rr(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
				else
					rb(&(*push)->stacks.stack_b);
			}
		}
		else
			ra(&(*push)->stacks.stack_a);
	}
	sorting_a((*push));
}

void	sorting_a(t_push *push)
{
	int	iterations;

	iterations = push->stacks.stack_a->size;
	while (push->stacks.stack_a->size > 5)
	{
		push->big_pivot = ((max_value(push) + min_value(push)) / 2);
		push->small_pivot = ((push->big_pivot + min_value(push)) / 2);
		iterations = push->stacks.stack_a->size;
		while (iterations--)
		{
			if ((*(int *)push->stacks.stack_a->first->content) \
			< push->big_pivot)
				pb(&push->stacks.stack_a, &push->stacks.stack_b);
			else
				ra(&push->stacks.stack_a);
		}
	}
	ft_printf("ANTES DA PARADA\n");
	sort_five(push);
}
