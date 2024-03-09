/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:20:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 12:29:47 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_build(t_push *stack, char **argv)
{
	t_stack	*new;
	int		idx;
	int		odx;
	char	**args;

	idx = 0;
	while (argv[++idx])
	{
		odx = -1;
		args = ft_split(argv[idx], ' ');
		while (args[++odx])
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
			}
			else
			{
				new->prev = stack->stack_a;
				new->prev = stack->stack_a;
				stack->stack_a->next = new;
				stack->stack_a = new;
				stack->size++;
			}
		}
		ft_free_split(args);
	}
}
