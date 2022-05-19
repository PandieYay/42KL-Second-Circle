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

static int	partition(t_array *array, int len)
{
	int	i;

	array->pi = 0;
	array->racount = 0;
	array->ori = array->sizea;
	array->median = findmedian(array->stacka, len);
	while (sortmedian(array) == 1)
	{
		if (array->stacka[0] < array->median)
		{
			pb(array);
			array->pi++;
		}
		else
		{
			ra(array);
			array->racount++;
		}
	}
	i = -1;
	if (array->ori != len)
		while (++i < array->racount)
			rra(array);
	return (array->pi);
}

static int	partitionb(t_array *array, int len)
{
	int	i;

	array->pi = 0;
	array->rbcount = 0;
	array->ori = array->sizeb;
	array->median = findmedian(array->stackb, len);
	while (sortmedianb(array) == 1)
	{
		if (array->stackb[0] >= array->median)
		{
			pa(array);
			array->pi++;
		}
		else
		{
			rb(array);
			array->rbcount++;
		}
	}
	i = -1;
	if (array->ori != len)
		while (++i < array->rbcount)
			rrb(array);
	return (array->pi);
}

void	quicksortb(t_array *array, int len)
{
	int	pi;

	if (len > 3)
	{
		pi = partitionb(array, len);
		len = len - pi;
		quicksort(array, pi);
		quicksortb(array, len);
	}
	else
		partitionisthreeb(array, len);
}

void	quicksort(t_array *array, int len)
{
	int	pi;

	if (len > 3)
	{
		pi = partition(array, len);
		len = len - pi;
		quicksort(array, len);
		quicksortb(array, pi);
	}
	else
	{
		if (len == array->sizea)
			insertionsort(array, len);
		else
			partitionisthree(array, len);
	}
}
