/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:30:56 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 09:08:33 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_dolist **stk_a, t_dolist **stk_b)
{
	int			idx;
	t_element	*aux;

	idx = 0;
	aux = (*stk_b)->first;
	while (aux)
	{
		aux->cost_a = get_min_value_rank((*stk_a), aux->rank);
		if (aux->cost_a > ((int)(*stk_a)->size / 2))
			aux->cost_a = aux->cost_a - (*stk_a)->size;
		if (idx > (int)(*stk_b)->size / 2)
			aux->cost_b = idx - (*stk_b)->size;
		else
			aux->cost_b = idx;
		aux = aux->next;
		idx++;
	}
}

void	get_cheap_cost(t_dolist **stk_a, t_dolist **stk_b)
{
	int			min;
	t_element	*tmp;
	t_element	*node;

	tmp = (*stk_b)->first;
	node = tmp;
	min = abs_math(tmp->cost_a) + abs_math(tmp->cost_b);
	while (tmp)
	{
		if ((abs_math(tmp->cost_a) + abs_math(tmp->cost_b)) < min)
		{
			min = abs_math(tmp->cost_a) + abs_math(tmp->cost_b);
			node = tmp;
		}
		tmp = tmp->next;
	}
	make_cheap_moves(stk_a, stk_b, node);
}

void	make_cheap_moves(t_dolist **stk_a, t_dolist **stk_b, t_element *node)
{
	int	costa;
	int	costb;

	costa = node->cost_a;
	costb = node->cost_b;
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		node->cost_a--;
		node->cost_b--;
		rr(stk_a, stk_b, 1);
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		node->cost_a++;
		node->cost_b++;
		rrr(stk_a, stk_b, 1);
	}
	if (node->cost_a > 0)
		ra(&(*stk_a), abs_math(node->cost_a));
	else if (node->cost_a < 0)
		rra(&(*stk_a), abs_math(node->cost_a));
	if (node->cost_b > 0)
		rb(&(*stk_b), abs_math(node->cost_b));
	else if (node->cost_b < 0)
		rrb(&(*stk_b), abs_math(node->cost_b));
}
