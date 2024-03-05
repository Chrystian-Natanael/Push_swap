/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:54 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/05 16:49:17 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str1, char *str2, unsigned int retrn)
{
	ft_putstr_fd("Push_swap: ", ERROR);
	ft_putstr_fd(str1, ERROR);
	ft_putendl_fd(str2, ERROR);
	exit(retrn);
}
