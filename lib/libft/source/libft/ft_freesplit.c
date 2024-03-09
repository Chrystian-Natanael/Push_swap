/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:32:26 by cnatanae          #+#    #+#             */
/*   Updated: 2024/03/09 10:32:43 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **split)
{
	int	idx;

	idx = 0;
	while (split[idx])
	{
		free(split[idx]);
		idx++;
	}
	free(split);
}