/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/13 15:05:40 by cnatanae         ###   ########.fr       */
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
	int		big_pivot;
	int		small_pivot;
	int		max_value;
	int		min_value;
}	t_push;

void	args_validation(char **args);
void	validation(int arg_nbr, char **args, t_push *push);
void	stack_build(t_push *push, char **argv);
void	compare(t_push *push);
int		list_to_compare(t_push *push);
void	signal_validation(char **args, int *idx, int *odx);
int		ft_isspace_line(char c);
void	create_lst(t_element *new, t_dolist **stack);
void	lst_clear(t_dolist **lst);

void	ft_swap(t_dolist **lst);
void	sa(t_dolist **stack_a);
void	sb(t_dolist **stack_b);
void	ss(t_dolist **stack_a, t_dolist **stack_b);

void	ft_push(t_dolist **stack_out, t_dolist **stack_in);
void	pa(t_dolist **stack_b, t_dolist **stack_a);
void	pb(t_dolist **stack_a, t_dolist **stack_b);

void	rotate(t_dolist **lst);
void	ra(t_dolist **stack_a);
void	rb(t_dolist **stack_b);
void	rr(t_dolist **stack_a, t_dolist **stack_b);

void	reverse_rotate(t_dolist **stack);
void	rra(t_dolist **stack_a);
void	rrb(t_dolist **stack_b);

void	get_pivots(t_push *push);
int		max_value(t_push *push);
int		min_value(t_push *push);

void	sort(t_push *push);
int		sort_validation(t_dolist **stack, t_push *push);
void	sort_three(t_push *push);
void	sort_four(t_push *push);
void	sort_five(t_push *push);

void	printfall(t_push *push); // !APAGAR

void	quick_sort(t_push **push);

#endif
