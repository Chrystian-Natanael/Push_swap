/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:20:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 15:15:23 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_push **push)
{
	int	iterations;

	iterations = (*push)->stacks.stack_a->size;
	ft_printf("\nITERATIONS: %d\n", (*push)->stacks.stack_a->size);
	ft_printf("\nBIG PIVOT: %d\n", (*push)->big_pivot);
	ft_printf("\nSMALL PIVOT: %d\n", (*push)->small_pivot);
	while (iterations--)
	{
		if ((*(int *)(*push)->stacks.stack_a->first->content) < (*push)->big_pivot)
		{
			pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
			if ((*push)->stacks.stack_b->size > 1 && (*(int *)(*push)->stacks.stack_b->first->content) < (*push)->small_pivot)
			{
				if ((*(int *)(*push)->stacks.stack_a->first->content) > (*push)->big_pivot)
					rr(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
				else
					rb(&(*push)->stacks.stack_b);
			}
		}
		else
			ra(&(*push)->stacks.stack_a);
	}
}
