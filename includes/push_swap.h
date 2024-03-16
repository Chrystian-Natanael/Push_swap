/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/16 19:38:12 by cnatanae         ###   ########.fr       */
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

# define SIZE_B (*push)->stacks.stack_b->size
# define SIZE_A (*push)->stacks.stack_a->size

# define CONTENT_A (*(int *)(*push)->stacks.stack_a->first->content)
# define SECONT_CONTENT_A (*(int *)(*push)->stacks.stack_a->first->next->content)
# define THIRD_CONTENT_A (*(int *)(*push)->stacks.stack_a->first->next->next->content)

# define FIRST_B (*push)->stacks.stack_b->first
# define FIRST_A (*push)->stacks.stack_a->first

# define CONTENT_B *(int *)(*push)->stacks.stack_b->first->content
# define SECONT_CONTENT_B (*(int *)(*push)->stacks.stack_b->first->next->content)
# define THIRD_CONTENT_B (*(int *)(*push)->stacks.stack_b->first->next->next->content)

#define LAST_A (*(int *)(*push)->stacks.stack_a->last->content)
#define LAST_B (*(int *)(*push)->stacks.stack_b->last->content)

# define RANK_B_FIRST (*push)->stacks.stack_b->first->rank
# define RANK_B_SECOND (*push)->stacks.stack_b->first->next->rank
# define RANK_B_LAST (*push)->stacks.stack_b->last->rank

# define RANK_A_FIRST (*push)->stacks.stack_a->first->rank
# define RANK_A_SECOND (*push)->stacks.stack_a->first->next->rank
# define RANK_A_LAST (*push)->stacks.stack_a->last->rank

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

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
}				t_chunk;

typedef struct s_split_dest
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_split_dest;

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
void	sa(t_dolist **stack_a, int count);
void	sb(t_dolist **stack_b, int count);
void	ss(t_dolist **stack_a, t_dolist **stack_b, int count);

void	ft_push(t_dolist **stack_out, t_dolist **stack_in);
void	pa(t_dolist **stack_b, t_dolist **stack_a, int count);
void	pb(t_dolist **stack_a, t_dolist **stack_b, int count);

void	rotate(t_dolist **lst);
void	ra(t_dolist **stack_a, int count);
void	rb(t_dolist **stack_b, int count);
void	rr(t_dolist **stack_a, t_dolist **stack_b, int count);

void	reverse_rotate(t_dolist **stack);
void	rra(t_dolist **stack_a, int count);
void	rrb(t_dolist **stack_b, int count);
void	rrr(t_dolist **stack_a, t_dolist **stack_b, int count);

void	get_pivots(t_push *push);
int		max_value(t_dolist *stk);
int		min_value(t_dolist *stk);

void	sort(t_push *push);
int		sort_validation(t_dolist **stack, t_push *push);

void	sort_three(t_dolist *stk);
void	sort_four(t_dolist *stk_a, t_dolist *stk_b, t_push *push);
void	sort_five(t_dolist *stk_a, t_dolist *stk_b, t_push *push);

int		value(t_dolist *stk, int n);
void	sort_three_rank(t_dolist *stk);

void	rank_linked_list(t_stack *stack);
void	quick_sort(t_push **push);
void	sorting_a(t_push **push);
void	b_to_a(t_push **push);
void	print_list(t_dolist *lst);
int		min_value_rank(t_dolist *stk, int value);
int		count_exist_rank(t_dolist *stack, int rank);
void	a_to_a(t_push **push);

int	count_exist_rank2(t_dolist *stack, int rank);

#endif
