/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/14 08:34:52 by cnatanae         ###   ########.fr       */
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
