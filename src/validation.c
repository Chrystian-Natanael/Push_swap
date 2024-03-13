/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 10:48:08 by cnatanae         ###   ########.fr       */
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
				ft_error(NOT_INT, args[idx], "");
		}
		if (ft_atol(args[idx]) > INT_MAX || ft_atol(args[idx]) < INT_MIN)
			ft_error(INT_OVERFLOW, args[idx], "");
	}
}

void	signal_validation(char **args, int *idx, int *odx)
{
	while (args[*idx][*odx] == '-')
	{
		if (!ft_isdigit(args[*idx][(*odx) + 1])
			&& !(args[*idx][(*odx) + 1] == '-'))
			ft_error(NOT_INT, args[*idx], "");
		(*odx)++;
	}
	while (args[*idx][*odx] == '+')
	{
		if (!ft_isdigit(args[*idx][(*odx) + 1])
			&& !(args[*idx][(*odx) + 1] == '+'))
			ft_error(NOT_INT, args[*idx], "");
		(*odx)++;
	}
	if (!ft_isdigit(args[*idx][*odx]) && !ft_isspace_line(args[*idx][*odx])
		&& args[*idx][*odx] != '\0')
		ft_error(NOT_INT, args[*idx], "");
}

void	validation(int arg_nbr, char **args, t_push *push)
{
	int			idx;
	int			odx;

	idx = 0;
	push->stacks.stack_a = NULL;
	push->stacks.stack_b = NULL;
	if (arg_nbr < 2)
		exit(EXIT_FAILURE);
	while (args[++idx])
	{
		odx = 0;
		if (ft_strlen(args[idx]) == 0 && (args[idx][0] == '\0'
			|| args[idx][0] == ' '))
			ft_error(INVALID_MSG, args[idx], "");
		while (args[idx][odx] == ' ')
		{
			if (args[idx][odx + 1] == '\0')
				ft_error(INVALID_MSG, args[idx], "");
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

	if (!(*stack))
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
	if (!push->stacks.stack_b)
	{
		lst_clear(stack);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
