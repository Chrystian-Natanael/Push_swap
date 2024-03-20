/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 09:28:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_validation(char **args)
{
	int	idx;
	int	odx;

	idx = 0;
	while (args[++idx])
	{
		odx = -1;
		while (args[idx][++odx])
		{
			signal_validation(args, &idx, &odx);
			if (ft_isdigit(args[idx][odx]) && !ft_isdigit(args[idx][odx + 1])
				&& !ft_isspace_line(args[idx][odx + 1])
				&& args[idx][odx + 1] != '\0')
				ft_error("", "", "");
		}
		if (ft_atol(args[idx]) > INT_MAX || ft_atol(args[idx]) < INT_MIN)
			ft_error("", "", "");
	}
}

void	signal_validation(char **args, int *idx, int *odx)
{
	while (args[*idx][*odx] == '-')
	{
		if (!ft_isdigit(args[*idx][(*odx) + 1])
			&& !(args[*idx][(*odx) + 1] == '-'))
			ft_error("", "", "");
		(*odx)++;
	}
	while (args[*idx][*odx] == '+')
	{
		if (!ft_isdigit(args[*idx][(*odx) + 1])
			&& !(args[*idx][(*odx) + 1] == '+'))
			ft_error("", "", "");
		(*odx)++;
	}
	if (!ft_isdigit(args[*idx][*odx]) && !ft_isspace_line(args[*idx][*odx])
		&& args[*idx][*odx] != '\0')
		ft_error("", "", "");
}

void	validation(int arg_nbr, char **args, t_push *push)
{
	int			idx;
	int			odx;

	idx = 0;
	push->stacks.stack_a = NULL;
	push->stacks.stack_b = NULL;
	if (arg_nbr < 2)
		exit(0);
	while (args[++idx])
	{
		odx = 0;
		if (ft_strlen(args[idx]) == 0 && (args[idx][0] == '\0'
			|| args[idx][0] == ' '))
			ft_error("", "", "");
		while (args[idx][odx] == ' ')
		{
			if (args[idx][odx + 1] == '\0')
				ft_error("", "", "");
			odx++;
		}
	}
	args_validation(args);
}

int	sort_validation(t_dolist **stack, t_push *push)
{
	int			tmp_value;
	t_element	*tmp_node_curr;
	t_element	*tmp_node;

	(void)push;
	if (!(*stack) || !(*stack)->first)
		return (-1);
	tmp_node = (*stack)->first;
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
