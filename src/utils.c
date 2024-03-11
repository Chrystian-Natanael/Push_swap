/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/11 09:56:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_line(char c)
{
	return (c == 9 || (c >= 11 && c <= 13) || c == ' ');
}

void	create_lst(t_element *new, t_push *push)
{
	push->stacks.stack_a = ft_calloc(1, sizeof(t_dolist));
	push->stacks.stack_a->first = new;
}

// {
// 	*tmp;
// 	*next;

// 	tmp = *lst;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		free(tmp);
// 		tmp = next;
// 	}
// }

// void	lst_clear(t_dolist **lst)
// {
// 	t_element	*tmp;
// 	t_element	*next;

// 	tmp = (*lst)->first;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		free(tmp);
// 		tmp = next;
// 	}
// 	free(*lst);
// }

void	lst_clear(t_dolist **lst)
{
	if (!lst)
		return ;
	while ((*lst)->first->next)
	{
		(*lst)->first = (*lst)->first->next;
		free((*lst)->first->prev);
		(*lst)->first->prev = NULL;
	}
	free((*lst)->first);
	free(*lst);
}