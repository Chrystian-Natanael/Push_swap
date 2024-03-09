/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 18:39:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push	push;

	validation(argc, argv, &push);
	stack_build(&push, argv);
	compare(&push);
	while (push.stacks.stack_a->first)
	{
		ft_printf("%d\n", (*(int *)push.stacks.stack_a->first->content));
		push.stacks.stack_a->first = push.stacks.stack_a->first->next;
	}
	return (0);
}
