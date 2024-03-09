/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 19:41:17 by cnatanae         ###   ########.fr       */
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
