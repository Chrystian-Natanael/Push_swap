/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:20:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/14 12:58:47 by cnatanae         ###   ########.fr       */
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
	sorting_a(push);
	b_to_a(push);
}

void	sorting_a(t_push **push)
{
	int	iterations;
	int	rrbs;

	iterations = SIZE_A;
	while (SIZE_A > 5)
	{
		(*push)->big_pivot = ((max_value(*push) + min_value(*push)) / 2);
		(*push)->small_pivot = (((*push)->big_pivot + min_value(*push)) / 2);
		iterations = (*push)->stacks.stack_a->size;
		rrbs = 0;
		while (iterations--)
		{
			if (SECONT_CONTENT_A < CONTENT_A \
			&& (SECONT_CONTENT_A < (*push)->big_pivot))
				sa(&(*push)->stacks.stack_a);
			if (CONTENT_A < (*push)->big_pivot)
				pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
			if (CONTENT_B > (*push)->small_pivot)
			{
				rb(&(*push)->stacks.stack_b);
				rrbs++;
			}
			else
				ra(&(*push)->stacks.stack_a);
		}
		while (rrbs--)
			rrb(&(*push)->stacks.stack_b);
	}
	sort(*push);
}

void	b_to_a(t_push **push)
{
	int	iterations;
	
	iterations = SIZE_B;
	while(iterations--)
	{
		while (CONTENT_A > SECONT_CONTENT_A)
		{
			sa(&(*push)->stacks.stack_a);
			if (SECONT_CONTENT_A > THIRD_CONTENT_A)
				ra(&(*push)->stacks.stack_a);
		}
		if (LAST_A > CONTENT_A && LAST_A != max_value(*push))
		{
				rra(&(*push)->stacks.stack_a);
				sa(&(*push)->stacks.stack_a);
		}
		else if ((CONTENT_B ) == max_value_b(*push))
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a);
		else if (LAST_B && (LAST_B) == max_value_b(*push))
		{
			rrb(&(*push)->stacks.stack_b);
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a);
		}
		else if ((SECONT_CONTENT_B ) && SECONT_CONTENT_B == max_value_b(*push))
		{
			sb(&(*push)->stacks.stack_b);
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a);
		}
		else if (THIRD_CONTENT_B != max_value_b(*push))
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a);
		else if (LAST_B > CONTENT_B)
			rrb(&(*push)->stacks.stack_b);
		else
			rb(&(*push)->stacks.stack_b);
		if (LAST_A > CONTENT_A && LAST_A < SECONT_CONTENT_A)
		{
			rra(&(*push)->stacks.stack_a);
			sa(&(*push)->stacks.stack_a);
			if (CONTENT_A > LAST_A)
				ra(&(*push)->stacks.stack_a);
		}
		iterations = SIZE_B + SIZE_A;
	}
}
