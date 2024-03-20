/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:25:31 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 09:09:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value_rank(t_dolist *stk, int value)
{
	int			min;
	t_element	*tmp;

	if (!stk)
		return (-1);
	tmp = stk->first;
	min = __INT_MAX__;
	while (tmp)
	{
		if (*((int *)tmp->content) < min && *((int *)tmp->content) > value)
			min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max_all_value_rank(t_dolist *stk)
{
	int			max;
	t_element	*tmp;

	if (!stk)
		return (-1);
	max = max_value(stk);
	tmp = stk->first;
	while (tmp)
	{
		if (*((int *)tmp->content) == max)
			break ;
		tmp = tmp->next;
	}
	return (tmp->rank);
}

int	min_value_rank_aa(t_dolist *stk, int value)
{
	int			min;
	t_element	*tmp;

	if (!stk)
		return (-1);
	tmp = stk->first;
	min = INT_MAX;
	if (max_all_value_rank(stk) < value)
		value = 0;
	while (tmp)
	{
		if (tmp->rank < min && tmp->rank > value)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

void	rank_linked_list(t_stack *stack)
{
	t_element	*tmp;
	int			rank;
	int			value;

	value = min_value(stack->stack_a);
	tmp = stack->stack_a->first;
	rank = 1;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
		{
			tmp->rank = rank;
			rank++;
			value = min_value_rank(stack->stack_a, value);
			tmp = stack->stack_a->first;
		}
		else
			tmp = tmp->next;
	}
}

int	get_min_value_rank(t_dolist *stack, int min)
{
	int			count;
	int			search;
	t_element	*temp;

	count = 0;
	temp = stack->first;
	search = min_value_rank_aa(stack, min);
	while (temp)
	{
		if (temp->rank == search)
			break ;
		temp = temp->next;
		count++;
	}
	return (count);
}
