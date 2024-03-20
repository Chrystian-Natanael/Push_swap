/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:36:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 11:26:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_command(t_dolist **a, t_dolist **b, char *command)
{
	if (!simple_comp(command, "pa\n"))
		ft_push(b, a);
	else if (!simple_comp(command, "pb\n"))
		ft_push(a, b);
	else if (!simple_comp(command, "sa\n"))
		ft_swap(a);
	else if (!simple_comp(command, "sb\n"))
		ft_swap(b);
	else if (!simple_comp(command, "ra\n"))
		rotate(a);
	else if (!simple_comp(command, "rb\n"))
		rotate(b);
	else if (!simple_comp(command, "rra\n"))
		reverse_rotate(a);
	else if (!simple_comp(command, "rrb\n"))
		reverse_rotate(b);
	else
		parse_command_more(a, b, command);
}

void	parse_command_more(t_dolist **a, t_dolist **b, char *command)
{
	if (!simple_comp(command, "rrr\n"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (!simple_comp(command, "rr\n"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!simple_comp(command, "ss\n"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		handle_error(a, b);
}

int	simple_comp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		++str1;
		++str2;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

void	handle_error(t_dolist **a, t_dolist **b)
{
	lst_clear(a);
	lst_clear(b);
	ft_putstr_fd("Error\n", ERROR);
	exit(EXIT_FAILURE);
}
