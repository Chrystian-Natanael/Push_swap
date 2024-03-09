/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:20:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 11:56:59 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_build(t_push *stack, char **argv)
{
	t_stack	*new;
	int		idx;
	int		odx;
	char	**args;

	idx = 1;
	while (argv[idx])
	{
		odx = 0;
		args = ft_split(argv[idx], ' ');
		while (args[odx])
		{
			new = malloc(sizeof(t_stack));
			if (!new)
				return ;
			new->value = ft_atoi(args[odx]);
			if (!stack->stack_a)
			{
				stack->stack_a = new;
				stack->first_a = stack->stack_a;
				stack->size++;
				ft_printf("%d\n", stack->stack_a->value);
			}
			else
			{
				new->prev = stack->stack_a;
				new->prev = stack->stack_a;
				stack->stack_a->next = new;
				stack->stack_a = new;
				stack->size++;
				ft_printf("%d %d\n", stack->stack_a->value, stack->stack_a->prev->value);
			}
			odx++;
		}
		ft_free_split(args);
		idx++;
	}
}
