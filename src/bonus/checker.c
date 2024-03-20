/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:32:52 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 12:31:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_push	push;

	validation(argc, argv, &push);
	stack_build(&push, argv);
	mid_parse(&push.stacks.stack_a, &push.stacks.stack_b);
	if (!sort_validation_checker(push.stacks.stack_a, &push)
		|| (push.stacks.stack_b && push.stacks.stack_b->first))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_checker(push.stacks.stack_a, push.stacks.stack_b);
	return (EXIT_SUCCESS);
}

void	free_checker(t_dolist *lst_a, t_dolist *lst_b)
{
	if (lst_a)
		lst_clear(&lst_a);
	if (lst_b)
		lst_clear(&lst_b);
}

void	mid_parse(t_dolist **a, t_dolist **b)
{
	char	*next_line;

	next_line = get_next_line(0);
	while (next_line)
	{
		parse_command(a, b, next_line);
		free(next_line);
		next_line = get_next_line(0);
	}
}

int	sort_validation_checker(t_dolist *stack, t_push *push)
{
	int			tmp_value;
	t_element	*tmp_node_curr;
	t_element	*tmp_node;

	(void)push;
	if (!stack || !stack->first)
		return (-1);
	tmp_node = stack->first;
	while (tmp_node)
	{
		tmp_value = *((int *)tmp_node->content);
		tmp_node_curr = tmp_node;
		while (tmp_node_curr)
		{
			if (tmp_value > *((int *)tmp_node_curr->content))
				return (0);
			tmp_node_curr = tmp_node_curr->next;
		}
		tmp_node = tmp_node->next;
	}
	return (1);
}
