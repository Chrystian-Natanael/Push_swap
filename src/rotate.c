/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:39:30 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/16 12:14:13 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_dolist **stack)
{
	t_element	*tmp;

	if (!(*stack) || !(*stack)->first)
		return ;
	tmp = (*stack)->first;
	ft_lstpop((*stack), 0);
	ft_dolstadd_back(stack, tmp);
}

void	ra(t_dolist **stack_a, int count)
{
	while (count--)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	rb(t_dolist **stack_b, int count)
{
	while (count--)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
}

void	rr(t_dolist **stack_a, t_dolist **stack_b, int count)
{
	while (count--)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}
