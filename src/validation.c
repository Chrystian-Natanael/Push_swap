/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 12:22:56 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_compare(t_push *stack)
{
	int		idx;
	int		compare;
	t_stack	*tmp;

	tmp = stack->first_a;
	while (tmp && tmp->next)
	{
		compare = 0;
		idx = 0;
		while (idx < stack->size)
		{
			if (tmp->value == stack->array[idx] && compare == 1)
				ft_error(INT_DUPLICATED, (ft_itoa(tmp->value)), "");
			else if (tmp->value == stack->array[idx])
				compare = 1;
			idx++;
		}
		tmp = tmp->next;
	}
	free(stack->array);
}

void	args_validation(char **args)
{
	int	idx;
	int	odx;

	idx = 0;
	while (args[++idx])
	{
		odx = -1;
		if (ft_atol(args[idx]) > INT_MAX || ft_atol(args[idx]) < INT_MIN)
			ft_error(INT_OVERFLOW, args[idx], "");
		while (args[idx][++odx])
		{
			signal_validation(args, &idx, &odx);
			if (ft_isdigit(args[idx][odx]) && !ft_isdigit(args[idx][odx + 1])
				&& !ft_isspace(args[idx][odx + 1])
				&& args[idx][odx + 1] != '\0')
				ft_error(NOT_INT, args[idx], "");
		}
	}
}

void	signal_validation(char **args, int *idx, int *odx)
{
	while (args[*idx][*odx] == '-')
	{
		if (!ft_isdigit(args[*idx][*odx + 1])
			&& !(args[*idx][*odx + 1] == '-'))
			ft_error(NOT_INT, args[*idx], "");
		odx++;
	}
	while (args[*idx][*odx] == '+')
	{
		if (!ft_isdigit(args[*idx][*odx + 1])
			&& !(args[*idx][*odx + 1] == '+'))
			ft_error(NOT_INT, args[*idx], "");
		(*odx)++;
	}
}

void	count_validation(int arg_nbr, char **args, t_push *push)
{
	const char	*str;

	push->size = 0;
	push->stack_a = NULL;
	push->stack_b = NULL;
	str = args[1];
	if (arg_nbr < 2)
		ft_error(PARAMETERS_MSG, "", "");
	if (arg_nbr == 2)
		if (ft_strlen(str) == 0 || str[0] == '\0' || str[0] == ' ')
			ft_error(INVALID_MSG, args[1], "");
}
