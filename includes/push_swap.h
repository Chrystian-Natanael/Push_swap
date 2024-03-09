/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 19:40:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// To use LIBFT functions
# include "libft.h"

// To use INT_MIN and INT_MAX
# include <limits.h>

# define PARAMETERS_MSG "Two or more parameters are required"
# define INVALID_MSG "Invalid argument: "
# define INT_DUPLICATED "Duplicated number: "
# define NOT_INT "Not a valid number: "
# define INT_OVERFLOW "Number overflow: "

typedef struct s_stack
{
	t_dolist	*stack_a;
	t_dolist	*stack_b;
}	t_stack;

typedef struct s_push
{
	t_stack	stacks;
	int		*array;
}	t_push;

void	args_validation(char **args);
void	validation(int arg_nbr, char **args, t_push *push);
void	stack_build(t_push *push, char **argv);
void	compare(t_push *push);
int		list_to_compare(t_push *push);
void	signal_validation(char **args, int *idx, int *odx);
int		ft_isspace_line(char c);
void	create_lst(t_element *new, t_push *push);

#endif
