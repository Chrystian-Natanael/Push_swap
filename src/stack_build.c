/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:20:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 15:54:25 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_build(t_push *push, char **argv)
{
	t_element	*new;
	int		idx;
	int		odx;
	int		*nbr;
	char	**args;

	idx = 0;
	while (argv[++idx])
	{
		odx = -1;
		args = ft_split(argv[idx], ' ');
		while (args[++odx])
		{
			nbr = malloc(sizeof(int));
			*nbr = ft_atoi(args[odx]);
			new = ft_lstnewelement((void *)nbr);
			if (!push->stacks.stack_a)
			{
				push->stacks.stack_a = malloc(sizeof(t_dolist));
				push->stacks.stack_a->first = new;
				push->size++;
			}
			else
			{
				ft_dolstadd_back(&push->stacks.stack_a, new);
				push->size++;
			}
		}
		ft_free_split(args);
	}
}
