/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksortalgo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:34:26 by edlim             #+#    #+#             */
/*   Updated: 2022/05/12 13:34:26 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	partition(t_array *array, int len)
{
	int	*sortedarray;
	int	i;
	int	pi;
	int	count;

	pi = 0;
	count = 0;
	sortedarray = array->stacka;
	count = bubblesort(sortedarray, len);
	i = -1;
	while (++i < len)
	{
		if (array->stacka[0] < count)
		{
			pb(array);
			pi++;
		}
		else
			ra(array);
	}
	return (pi);
}

void	quicksortb(t_array *array, int len)
{
	int	pi;

	if (len > 3)
	{
		pi = partition(array, len);
		len = len - pi;
		// quicksort(array, pi);
	}
	insertionsortb(array, len);
	pa(array);
	pa(array);
}

void	quicksort(t_array *array, int len)
{
	int	pi;

	if (len > 3)
	{
		pi = partition(array, len);
		len = len - pi;
		quicksort(array, array->sizea);
		// quicksortb(array, pi);
	}
	insertionsort(array, len);
}

