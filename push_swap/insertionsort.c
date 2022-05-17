/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:27:54 by edlim             #+#    #+#             */
/*   Updated: 2022/05/16 10:27:55 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertionsort(t_array *array, int n)
{
	int	i;
	int	k;

	i = 1;
	while (i < n)
	{
		k = i - 1;
		while (k >= 0 && array->stacka[k] > array->stacka[i])
		{
			if (array->stacka[0] > array->stacka[1])
				sa(array);
			else
				rra(array);
			k = k - 1;
		}
		if (array->stacka[0] > array->stacka[1])
			sa(array);
		i++;
	}
}
