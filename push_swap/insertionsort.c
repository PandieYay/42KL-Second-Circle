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

static void	partitionisthreehelper(t_array *array, int option)
{
	if (option == 0)
	{
		sa(array);
		ra(array);
		sa(array);
		rra(array);
		sa(array);
	}
	if (option == 1)
	{
		pb(array);
		sa(array);
		pa(array);
		sa(array);
	}
}

void	partitionisthree(t_array *array, int len)
{
	if (len == 2)
	{
		if (array->stacka[0] > array->stacka[1])
			sa(array);
	}
	else if (array->stacka[0] > array->stacka[1]
		&& array->stacka[0] > array->stacka[2])
	{
		if (array->stacka[1] > array->stacka[2])
			partitionisthreehelper(array, 0);
		else
		{
			sa(array);
			ra(array);
			sa(array);
			rra(array);
		}
	}
	else if (array->stacka[1] > array->stacka[0]
		&& array->stacka[1] > array->stacka[2])
	{
		if (array->stacka[0] > array->stacka[2])
			partitionisthreehelper(array, 1);
		else
		{
			ra(array);
			sa(array);
			rra(array);
		}
	}
	else if (array->stacka[2] > array->stacka[0]
		&& array->stacka[2] > array->stacka[1])
		if (array->stacka[0] > array->stacka[1])
			sa(array);
}

static void	partitionisthreehelperb(t_array *array, int option)
{
	if (option == 0)
	{
		pa(array);
		sb(array);
		pa(array);
		pa(array);
	}
	if (option == 1)
	{
		sb(array);
		pa(array);
		pa(array);
		pa(array);
	}
}

void	partitionisthreeb(t_array *array, int len)
{
	if (len == 1)
		pa(array);
	else if (len == 2)
	{
		if (array->stackb[1] > array->stackb[0])
			sb(array);
		pa(array);
		pa(array);
	}
	else if (array->stackb[0] > array->stackb[1]
		&& array->stackb[0] > array->stackb[2])
	{
		if (array->stackb[1] > array->stackb[2])
		{
			pa(array);
			pa(array);
			pa(array);
		}
		else
			partitionisthreehelperb(array, 0);
	}
	else if (array->stackb[1] > array->stackb[0]
		&& array->stackb[1] > array->stackb[2])
	{
		if (array->stackb[0] > array->stackb[2])
			partitionisthreehelperb(array, 1);
		else
		{
			sb(array);
			pa(array);
			sb(array);
			pa(array);
			pa(array);
		}
	}
	else if (array->stackb[2] > array->stackb[0]
		&& array->stackb[2] > array->stackb[1])
	{
		if (array->stackb[0] > array->stackb[1])
		{
			rb(array);
			sb(array);
			pa(array);
			rrb(array);
			pa(array);
			pa(array);
		}
		else
		{
			rb(array);
			sb(array);
			pa(array);
			pa(array);
			rrb(array);
			pa(array);
		}
	}
}

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

void	insertionsortb(t_array *array, int n)
{
	int	i;
	int	k;

	i = 1;
	while (i < n)
	{
		k = i - 1;
		while (k >= 0 && array->stackb[i] > array->stackb[k])
		{
			if (array->stackb[1] > array->stackb[0])
				sb(array);
			else
				rrb(array);
			k = k - 1;
		}
		if (array->stackb[1] > array->stackb[0])
			sb(array);
		i++;
	}
}
