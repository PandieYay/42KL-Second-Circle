/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitionisthree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:09:39 by edlim             #+#    #+#             */
/*   Updated: 2022/05/17 18:09:40 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	piis3helper2(t_array *array, int option)
{
	if (option == 2)
	{
		pb(array);
		sa(array);
		pa(array);
		sa(array);
	}
	else if (option == 3)
	{
		ra(array);
		sa(array);
		rra(array);
	}
}

static void	piis3helper(t_array *array, int option)
{
	if (option == 0)
	{
		sa(array);
		ra(array);
		sa(array);
		rra(array);
		sa(array);
	}
	else if (option == 1)
	{
		sa(array);
		ra(array);
		sa(array);
		rra(array);
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
			piis3helper(array, 0);
		else
			piis3helper(array, 1);
	}
	else if (array->stacka[1] > array->stacka[0]
		&& array->stacka[1] > array->stacka[2])
	{
		if (array->stacka[0] > array->stacka[2])
			piis3helper2(array, 2);
		else
			piis3helper2(array, 3);
	}
	else if (array->stacka[0] > array->stacka[1])
		sa(array);
}
