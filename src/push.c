/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:39:34 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/11 15:08:39 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_dolist **stack_out, t_dolist **stack_in)
{
	t_element	*tmp;

	if (!stack_out || !(*stack_out)->first)
		return ;
	tmp = (*stack_out)->first;
	ft_lstpop((*stack_out), 0);
	if (!(*stack_in))
	{
		create_lst(tmp, stack_in);
		(*stack_in)->size++;
	}
	else
		ft_dolstadd_front(stack_in, tmp);
}

void	pa(t_dolist **stack_b, t_dolist **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_dolist **stack_a, t_dolist **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
