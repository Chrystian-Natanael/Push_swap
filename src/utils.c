/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 15:20:25 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_line(char c)
{
	return (c == 9 ||(c >=11 && c <= 13) || c == ' ');
}
int	list_to_compare(t_push *push)
{
	int			idx;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	push->array = malloc(sizeof(int) * push->size);
	if (!push->array)
		return (1);
	idx = 0;
	while (tmp)
	{
		push->array[idx] = *((int*)tmp->content);
		tmp = tmp->next;
		idx++;
	}
	return (0);
}
