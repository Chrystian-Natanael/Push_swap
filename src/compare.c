/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:36:56 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 10:06:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_to_compare(t_push *push)
{
	int			idx;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	push->array = ft_calloc(1, sizeof(int) * push->stacks.stack_a->size);
	if (!push->array)
		return (1);
	idx = 0;
	while (tmp)
	{
		push->array[idx] = *((int *)tmp->content);
		tmp = tmp->next;
		idx++;
	}
	return (0);
}

void	compare(t_push *push)
{
	int			idx;
	int			compare;
	t_element	*tmp;

	list_to_compare(push);
	tmp = push->stacks.stack_a->first;
	while (tmp && tmp->next)
	{
		compare = 0;
		idx = 0;
		while (idx < (int)push->stacks.stack_a->size)
		{
			if (*((int *)tmp->content) == push->array[idx] && compare == 1)
			{
				free(push->array);
				lst_clear(&push->stacks.stack_a);
				ft_error(INT_DUPLICATED, "", "");
			}
			else if (*((int *)tmp->content) == push->array[idx])
				compare = 1;
			idx++;
		}
		tmp = tmp->next;
	}
	free(push->array);
}
