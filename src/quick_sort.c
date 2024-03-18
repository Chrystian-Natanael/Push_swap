/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:20:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/18 18:30:57 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_push **push)
{
	int	big_pivot;
	int	small_pivot;
	int	size;
	int	n;

	size = SIZE_A;
	n = 22;
	small_pivot = (int)SIZE_A / n;
	big_pivot = (int)SIZE_A / (n / 2);
	while (SIZE_A > 5)
	{
		while (count_exist_rank((*push)->stacks.stack_a, big_pivot) && SIZE_A > 5)
		{
			if ((*push)->stacks.stack_a->first->rank < big_pivot)
			{
				pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
				if (SIZE_B > 1 && RANK_B_FIRST < small_pivot)
				{
					if ((*push)->stacks.stack_a->first->rank > small_pivot)
						rr(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
					else
						rb(&(*push)->stacks.stack_b, 1);
				}
			}
			else
				ra(&(*push)->stacks.stack_a, 1);
		}
		if (count_exist_rank((*push)->stacks.stack_a, big_pivot) == 0)
		{
			small_pivot += (int)size/(n / 2);
			big_pivot += (int)size/(n / 2);
		}
	}
	sort(*push);
	b_to_a(push);
}

int	count_exist_rank(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank < rank)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	count_exist_rank2(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank > rank)
			count++;
		temp = temp->next;
	}
	return (count);
}


void	print_stack(t_dolist *a, t_dolist *b)
{
	t_element	*aux;
	(void)a;
	aux = a->first;
	fprintf(stderr, "\n\n");
	fprintf(stderr, "|----------|\n");
	fprintf(stderr, "| stack a: |\n");
	fprintf(stderr, "|-------|--|-----------|----------------|\n");
	fprintf(stderr, "| value | sorted index |      next      |\n");
	fprintf(stderr, "|-------|--------------|----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %14p |\n", *((int *)aux->content), aux->rank, aux->next);
		aux = aux->next;
	}
	fprintf(stderr, "|-------|--------------|----------------|\n\n");
	aux = b->first;
	fprintf(stderr, "|----------|\n");
	fprintf(stderr, "| stack b: |\n");
	fprintf(stderr, "|-------|--|-----------|----------------|\n");
	fprintf(stderr, "| value | sorted index |      next      |\n");
	fprintf(stderr, "|-------|--------------|----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %14p |\n", *((int *)aux->content), aux->rank, aux->next);
		aux = aux->next;
	}
	fprintf(stderr, "|-------|--------------|----------------|\n");
	fflush(stderr);
}




int	get_min_value_rank(t_dolist *stack, int min)
{
	t_element	*temp;
	int			count;
	int			search;

	count = 0;
	temp = stack->first;
	search = min_value_rank_aa(stack, min);
	while (temp)
	{
		if (temp->rank == search)
			break ;
		temp = temp->next;
		count++;
	}
	return (count);
}

void	b_to_a(t_push **push)
{
	int	big_pivot;
	int	small_pivot;
	int	n;
	int	size;
	int	cost;

	n = 2;
	size = SIZE_B;
	big_pivot = size - size / (22 / n);
	small_pivot = size - size / (22 / n + 3);
	
	while (SIZE_B != 0)
	{
		while (count_exist_rank2((*push)->stacks.stack_b, big_pivot))
		{
			if (RANK_B_LAST > RANK_B_FIRST)
				rrb(&(*push)->stacks.stack_b, 1);
			cost = get_min_value_rank((*push)->stacks.stack_a, RANK_B_FIRST);
			print_stack((*push)->stacks.stack_a, (*push)->stacks.stack_b);
			fprintf(stderr, "(%i)\n", cost);
			if (cost < ((int)(SIZE_A) / 2))
				ra(&(*push)->stacks.stack_a, cost);
			else 
				rra(&(*push)->stacks.stack_a, SIZE_A - cost);
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
		}
		if (RANK_B_FIRST < small_pivot && RANK_B_LAST < small_pivot)
		{
			n += 2;
			big_pivot = size - size / (22 / n);
			small_pivot = size - size / (22 / n + 3);
		}
	}
}

