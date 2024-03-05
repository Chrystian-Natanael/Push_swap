/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:01:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/05 17:36:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // ! DELETE THIS

/* read, write*/
# include <unistd.h>

/*malloc, free, exit*/
# include <stdlib.h>

/*libft*/
# include "libft.h"

/*Enum's*/
typedef enum e_exit
{
	SUCESS,
	FAILURE,
}	t_exit;

typedef enum e_type
{
	TOP,
	MID,
	LAST,
}	t_type;

typedef enum e_return
{
	IN,
	OUT,
	ERROR,
}	t_return;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	t_type			type;
}	t_stack;

typedef struct s_push
{
	int		qtd;
	t_stack	*a;
	t_stack	*b;
}	t_push;

/*Functions*/

void	error(char *str1, char *str2, unsigned int retrn);
int		ft_isspace(int c);
void	validade_args(int argc, char **argv, t_push *push);
void	add_nodes_value(t_push *push, char *value);
t_stack	*create_node(int type, char *value);
void	validade_arg_str(char *numbers, t_push *push);

#endif