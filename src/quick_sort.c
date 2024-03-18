/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:20:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/18 11:27:49 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_push **push)
{
	int	big_pivot;
	int	small_pivot;
	int	size;
	int	n;

	size = SIZE_A;
	n = 22;
	small_pivot = (int)SIZE_A / n;
	big_pivot = (int)SIZE_A / (n / 2);
	while (SIZE_A >= 5)
	{
		while (count_exist_rank((*push)->stacks.stack_a, big_pivot) && SIZE_A >= 5)
		{
			if ((*push)->stacks.stack_a->first->rank < big_pivot)
			{
				pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
				if (SIZE_B > 1 && RANK_B_FIRST < small_pivot)
				{
					if ((*push)->stacks.stack_a->first->rank > small_pivot)
						rr(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
					else
						rb(&(*push)->stacks.stack_b, 1);
				}
			}
			else
				ra(&(*push)->stacks.stack_a, 1);
		}
		if (count_exist_rank((*push)->stacks.stack_a, big_pivot) == 0)
		{
			small_pivot += (int)size/(n / 2);
			big_pivot += (int)size/(n / 2);
		}
	}
	sort(*push);
	b_to_a(push);
}

int	count_exist_rank(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank < rank)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	count_exist_rank2(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank > rank)
			count++;
		temp = temp->next;
	}
	return (count);
}

void	b_to_a(t_push **push)
{
	int	big_pivot;
	int	small_pivot;
	int	n;
	int	size;

	n = 2;
	size = SIZE_B;
	big_pivot = size - size / (22 / n);
	small_pivot = size - size / (22 / n + 3);
	while (SIZE_B != 0)
	{
		while (count_exist_rank2((*push)->stacks.stack_b, big_pivot))
		{
			if (RANK_B_FIRST > big_pivot && RANK_B_FIRST > RANK_B_LAST)
				pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
			else if (RANK_B_LAST > RANK_B_FIRST)
			{
				rrb(&(*push)->stacks.stack_b, 1);
				pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
			}
			else
				rb(&(*push)->stacks.stack_b, 1);
		}
		if (RANK_B_FIRST < small_pivot && RANK_B_LAST < small_pivot)
		{
			n += 2;
			big_pivot = size - size / (20 / n);
			small_pivot = size - size / (20 / n + 3);
		}
		
	}
}

void	a_to_a(t_push **push)
{
	if (SECONT_CONTENT_A < CONTENT_A)
		sa(&(*push)->stacks.stack_a, 1);
	else if (LAST_A != max_value((*push)->stacks.stack_a) && LAST_A < CONTENT_A)
	{
		rra(&(*push)->stacks.stack_a, 1);
		sa(&(*push)->stacks.stack_a, 1);
	}
}