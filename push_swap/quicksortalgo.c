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
	int	i;
	int	pi;
	int	ori;
	int	count;
	int	racount;

	pi = 0;
	count = 0;
	racount = 0;
	ori = array->sizea;
	count = bubblesort(array->stacka, len);
	i = -1;
	while (++i < len)
	{
		if (array->stacka[0] < count)
		{
			pb(array);
			pi++;
		}
		else
		{
			ra(array);
			racount++;
		}
	}
	if (ori != len)
	{
		i = -1;
		while (++i < racount)
			rra(array);
	}
	return (pi);
}

static int	partitionb(t_array *array, int len)
{
	int	i;
	int	pi;
	int	ori;
	int	count;
	int	rbcount;

	pi = 0;
	count = 0;
	rbcount = 0;
	ori = array->sizeb;
	count = bubblesort(array->stackb, len);
	i = -1;
	while (++i < len)
	{
		if (array->stackb[0] >= count)
		{
			pa(array);
			pi++;
		}
		else
		{
			rb(array);
			rbcount++;
		}
	}
	if (ori != len)
	{
		i = -1;
		while (++i < rbcount)
			rrb(array);
	}
	return (pi);
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
	{
		insertionsortb(array, len);
		pa(array);
		pa(array);
		if (array->sizeb == 1)
			pa(array);
	}
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
