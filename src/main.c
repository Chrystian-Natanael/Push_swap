/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/12 09:25:27 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		push;
	t_element	*tmp;

	validation(argc, argv, &push);
	stack_build(&push, argv);
	compare(&push);
	ft_printf("\n--------MOVEMENTS:--------\n\n");
	pb(&push.stacks.stack_a, &push.stacks.stack_b);
	pb(&push.stacks.stack_a, &push.stacks.stack_b);
	pb(&push.stacks.stack_a, &push.stacks.stack_b);
	rrb(&push.stacks.stack_b);
	sb(&push.stacks.stack_b);
	ft_printf("\n--------STACK A:--------\n\n");
	tmp = push.stacks.stack_a->first;
	while (tmp)
	{
		ft_printf("%d\n", (*(int *)tmp->content));
		tmp = tmp->next;
	}
	ft_printf("\n--------STACK B:--------\n\n");
	tmp = push.stacks.stack_b->first;
	while (tmp)
	{
		ft_printf("%d\n", (*(int *)tmp->content));
		tmp = tmp->next;
	}
	lst_clear(&push.stacks.stack_a);
	lst_clear(&push.stacks.stack_b);
	return (0);
}
