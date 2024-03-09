/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:36:56 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 19:41:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_to_compare(t_push *push)
{
	int			idx;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	push->array = malloc(sizeof(int) * push->stacks.stack_a->size);
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
				ft_error(INT_DUPLICATED, (ft_itoa(*((int *)tmp->content))), "");
			else if (*((int *)tmp->content) == push->array[idx])
				compare = 1;
			idx++;
		}
		tmp = tmp->next;
	}
	free(push->array);
}
