/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:02:35 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/05 17:55:01 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	validade_args(int argc, char **argv, t_push *push)
{
	char	**nbrs;
	int		idx;

	idx = 0;
	if (argc < 2)
		error("format invalid", "", ERROR);
	else if (argc == 2)
	{
		validade_arg_str(argv[1], push);
		nbrs = ft_split(argv[1], ' ');
		push->a = create_node(TOP, nbrs[idx]);
		while (nbrs[++idx])
			add_nodes_value(push, nbrs[idx]);
	}
	
}

void	add_nodes_value(t_push *push, char *value)
{
	t_stack *new_node;
	
	if (push->a->next == NULL)
	{
		new_node = create_node(LAST, value);
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
		new_node = create_node(LAST, value);
		new_node->prev = push->a;
		new_node->next = push->a->next;
		push->a->type = MID;
		push->a->next = new_node;
		push->a = push->a->next;
		push->a = push->a->next;
		push->a->prev = new_node;
	}
}

t_stack	*create_node(int type, char *value)
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

void	validade_arg_str(char *numbers, t_push *push)
{
	int	idx;

	idx = -1;
	push->qtd = 0;
	while (numbers[++idx])
	{
		if (!ft_isspace(numbers[idx]) && !ft_isdigit(numbers[idx]))
			error("invalid string in ",numbers , ERROR);
		if (ft_isdigit(numbers[idx]) && (ft_isspace(numbers[idx + 1])
			|| numbers[idx + 1] == '\0'))
			push->qtd++;
	}
	
}
