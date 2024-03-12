/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:22:36 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/12 09:28:31 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_dolist **stack)
{
	t_element	*tmp;

	if (!(*stack) || !(*stack)->first || !(*stack)->last)
		return ;
	tmp = (*stack)->last;
	ft_lstpop((*stack), (*stack)->size - 1);
	ft_dolstadd_front(stack, tmp);
}

void	rra(t_dolist **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_dolist **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_dolist **stack_a, t_dolist **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
