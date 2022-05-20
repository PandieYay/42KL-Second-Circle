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

void	insertionsort(t_array *array, int len)
{
	if (len == 2)
	{
		if (array->stacka[0] > array->stacka[1])
			sa(array);
	}
	else if (array->stacka[0] > array->stacka[1]
		&& array->stacka[0] > array->stacka[2])
	{
		ra(array);
		if (array->stacka[0] > array->stacka[1])
			sa(array);
	}
	else if (array->stacka[1] > array->stacka[0]
		&& array->stacka[1] > array->stacka[2])
	{
		rra(array);
		if (array->stacka[0] > array->stacka[1])
			sa(array);
	}
	else if (array->stacka[2] > array->stacka[0]
		&& array->stacka[2] > array->stacka[1])
		if (array->stacka[0] > array->stacka[1])
			sa(array);
}

static void	insertionsortbhelper(t_array *array, int option)
{
	if (option == 0)
	{
		pa(array);
		pa(array);
		pa(array);
	}
	else if (option == 1)
	{
		pa(array);
		sb(array);
		pa(array);
		pa(array);
	}
}

void	insertionsortb(t_array *array, int len)
{
	if (len == 1 || len == 2)
		partitionisthreeb(array, len);
	else if (array->stackb[0] > array->stackb[1]
		&& array->stackb[0] > array->stackb[2])
		partitionisthreeb(array, len);
	else if (array->stackb[1] > array->stackb[0]
		&& array->stackb[1] > array->stackb[2])
		partitionisthreeb(array, len);
	else if (array->stackb[2] > array->stackb[0]
		&& array->stackb[2] > array->stackb[1])
	{
		rrb(array);
		if (array->stackb[1] > array->stackb[2])
			insertionsortbhelper(array, 0);
		else
			insertionsortbhelper(array, 1);
	}
}
