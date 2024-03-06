/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:02:35 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/06 09:21:16 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validade_args(int argc, char **argv, t_push *push)
{
	char	**nbrs;
	int		idx;
	int		odx;

	push->a = NULL;
	validade_errors_init(argc, argv, push, &idx);
	while (argv[++idx])
	{
		odx = 0;
		if (argv[idx] && ft_strlen(argv[idx]) > 1)
		{
			nbrs = ft_split(argv[idx], ' ');
			while (nbrs[odx])
				add_nodes_str(push, nbrs[odx++]);
			free_split(nbrs);
		}
		else
			add_nodes_str(push, argv[idx]);
	}
}

void	validade_errors_init(int argc, char **argv, t_push *push, int *idx)
{
	char	**nbrs;
	int		odx;

	*idx = 0;
	odx = 0;
	if (argc < 2)
		error("format invalid", "", ERROR);
	while (argv[++(*idx)])
		validade_arg_str(argv[*idx], push);
	*idx = 1;
	if (argv[*idx] && ft_strlen(argv[*idx]) > 1)
	{
		nbrs = ft_split(argv[*idx], ' ');
		push->a = create_node_str(TOP, nbrs[odx++]);
		while (nbrs[odx])
			add_nodes_str(push, nbrs[odx++]);
		free_split(nbrs);
		*idx = 1;
	}
	else if (push->qtd > 0)
		push->a = create_node_str(TOP, argv[*idx]);
}

void	validade_arg_str(char *numbers, t_push *push)
{
	int	idx;

	idx = -1;
	push->qtd = 0;
	while (numbers[++idx])
	{
		if (!ft_isspace(numbers[idx]) && !ft_isdigit(numbers[idx]))
			error("invalid string in ", numbers, ERROR);
		if (ft_isdigit(numbers[idx]) && (ft_isspace(numbers[idx + 1])
				|| numbers[idx + 1] == '\0'))
			push->qtd++;
	}
}
