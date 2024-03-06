/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:59:28 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/06 09:23:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_nodes_str(t_push *push, char *value)
{
	t_stack	*new_node;

	if (push->a->next == NULL)
	{
		new_node = create_node_str(LAST, value);
		new_node->next = push->a;
		new_node->prev = push->a;
		push->a->next = new_node;
		push->a->prev = new_node;
	}
	else
	{
		push->a = push->a->next;
		while (push->a->next && push->a->next->type != TOP)
			push->a = push->a->next;
		new_node = create_node_str(LAST, value);
		new_node->prev = push->a;
		new_node->next = push->a->next;
		push->a->type = MID;
		push->a->next = new_node;
		push->a = push->a->next;
		push->a = push->a->next;
		push->a->prev = new_node;
	}
}

t_stack	*create_node_str(int type, char *value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->type = type;
	new_node->value = ft_atoi(value);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
