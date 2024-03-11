/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/11 15:07:14 by cnatanae         ###   ########.fr       */
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
	pb(&push.stacks.stack_a, &push.stacks.stack_b);
	pb(&push.stacks.stack_a, &push.stacks.stack_b);
	pb(&push.stacks.stack_a, &push.stacks.stack_b);
	sb(push.stacks.stack_b);
	tmp = push.stacks.stack_a->first;
	ft_printf("\nSTACK A:\n");
	while (tmp)
	{
		ft_printf("%d\n", (*(int *)tmp->content));
		tmp = tmp->next;
	}
	tmp = push.stacks.stack_b->first;
	ft_printf("\nSTACK B:\n");
	while (tmp)
	{
		ft_printf("%d\n", (*(int *)tmp->content));
		tmp = tmp->next;
	}
	lst_clear(&push.stacks.stack_a);
	lst_clear(&push.stacks.stack_b);
	return (0);
}
