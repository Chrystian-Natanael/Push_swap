/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:20:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/16 20:19:52 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_push **push)
{
	int	iteration;
	int	big_pivot;
	int	small_pivot;
	int	size;
	int	n;

	size = SIZE_A;
	n = 16;
	small_pivot = (int)SIZE_A / n;
	big_pivot = (int)SIZE_A / (n / 2);
	iteration = SIZE_A;
	while (count_exist_rank((*push)->stacks.stack_a, big_pivot) && SIZE_A > 5)
	{
		if ((*push)->stacks.stack_a->first->rank < big_pivot)
		{
			pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
			if (SIZE_B > 1 && RANK_B_FIRST > small_pivot)
			{
				
				if ((*push)->stacks.stack_a->first->rank > small_pivot)
					rr(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
				else
					rb(&(*push)->stacks.stack_b, 1);
			}
		}
		else
			ra(&(*push)->stacks.stack_a, 1);
		if (count_exist_rank((*push)->stacks.stack_a, big_pivot) == 0)
		{
			n -= 2;
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
	int	n;

	n = 16;
	big_pivot = (int)SIZE_B - ((int)SIZE_B / (16 / 2));
	while(count_exist_rank2((*push)->stacks.stack_b, big_pivot))
	{
		if (RANK_B_LAST > big_pivot)
		{
			rrb(&(*push)->stacks.stack_b, 1);
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
		}
		else if (RANK_B_FIRST > big_pivot)
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
		else
			rb(&(*push)->stacks.stack_b, 1);
		if (count_exist_rank2((*push)->stacks.stack_b, big_pivot) == 0)
		{
			n -= 2;
			big_pivot -= (int)SIZE_B/(n / 3);
		}
		a_to_a(push);
		// pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
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