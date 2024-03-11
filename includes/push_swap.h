/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/11 15:05:05 by cnatanae         ###   ########.fr       */
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
// void	create_lst(t_element *new, t_push *push);
void	create_lst(t_element *new, t_dolist **stack);
void	lst_clear(t_dolist **lst);




void	ft_swap(t_dolist *lst);
void	sa(t_dolist *stack_a);
void	sb(t_dolist *stack_b);
void	ss(t_dolist *stack_a, t_dolist *stack_b);

void	ft_push(t_dolist **stack_out, t_dolist **stack_in);
void	pa(t_dolist **stack_b, t_dolist **stack_a);
void	pb(t_dolist **stack_a, t_dolist **stack_b);

#endif
