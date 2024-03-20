/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:36:43 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/20 07:40:57 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_exist_rank(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank < rank)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	count_exist_rank2(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank > rank)
			count++;
		temp = temp->next;
	}
	return (count);
}

void	init_pivots(t_pivot *pivot, int size)
{
	pivot->n = 2;
	pivot->big_pivot = size - size / (22 / pivot->n);
	pivot->small_pivot = size - size / (22 / pivot->n + 3);
}

void	ft_error(char *str1, char *str2, char *str3)
{
	(void) str1;
	(void) str2;
	(void) str3;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
