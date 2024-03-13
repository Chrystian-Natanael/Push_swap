/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 10:46:31 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		push;

	validation(argc, argv, &push);
	stack_build(&push, argv);
	compare(&push);
	sort(&push);
	lst_clear(&push.stacks.stack_a);
	lst_clear(&push.stacks.stack_b);
	return (0);
}
// ! APAGAR
void	printfall(t_push *push)
{
	t_element	*tmp;
	
	ft_printf("\n--------STACK A:--------\n\n");
	tmp = push->stacks.stack_a->first;
	while (tmp)
	{
		ft_printf("%d\n", (*(int *)tmp->content));
		tmp = tmp->next;
	}
	if (push->stacks.stack_b)
	{
		ft_printf("\n--------STACK B:--------\n\n");
		tmp = push->stacks.stack_b->first;
		while (tmp)
		{
			ft_printf("%d\n", (*(int *)tmp->content));
			tmp = tmp->next;
		}
	}
}
