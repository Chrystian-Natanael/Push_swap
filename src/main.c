/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:00:31 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/06 09:22:45 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push	push;
	int		idx;

	idx = 0;
	validade_args(argc, argv, &push);
	if (push.a)
		ft_printf("Node %d: %d and your type is %d\n", idx, \
			push.a->value, push.a->type);
	if (push.a && push.a->next)
		push.a = push.a->next;
	idx++;
	while (push.a && push.a->type != TOP)
	{
		ft_printf("Node %d: %d and your type is %d\n", idx, \
			push.a->value, push.a->type);
		push.a = push.a->next;
		idx++;
	}
	if (push.a)
		free_stack(push.a);
	return (0);
}
