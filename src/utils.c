/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/11 14:57:40 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_line(char c)
{
	return (c == 9 || (c >= 11 && c <= 13) || c == ' ');
}

void	create_lst(t_element *new, t_dolist **stack)
{
	(*stack) = ft_calloc(1, sizeof(t_dolist));
	(*stack)->first = new;
}

void	lst_clear(t_dolist **lst)
{
	if (!lst)
		return ;
	while ((*lst)->first && (*lst)->first->next)
	{
		(*lst)->first = (*lst)->first->next;
		free((*lst)->first->prev->content);
		free((*lst)->first->prev);
		(*lst)->first->prev = NULL;
	}
	if ((*lst)->first)
		free((*lst)->first->content);
	free((*lst)->first);
	free(*lst);
}