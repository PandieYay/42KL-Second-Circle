/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitionisthreeb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:09:39 by edlim             #+#    #+#             */
/*   Updated: 2022/05/17 18:23:47 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	piis3helper3(t_array *array, int option)
{
	if (option == 5)
	{
		rb(array);
		sb(array);
		pa(array);
		pa(array);
		rrb(array);
		pa(array);
	}
}

static void	piis3helper2(t_array *array, int option)
{
	if (option == 3)
	{
		sb(array);
		pa(array);
		sb(array);
		pa(array);
		pa(array);
	}
	if (option == 4)
	{
		rb(array);
		sb(array);
		pa(array);
		rrb(array);
		pa(array);
		pa(array);
	}
}

static void	piis3helper(t_array *array, int option)
{
	if (option == 0)
	{
		pa(array);
		pa(array);
		pa(array);
	}
	if (option == 1)
	{
		pa(array);
		sb(array);
		pa(array);
		pa(array);
	}
	if (option == 2)
	{
		sb(array);
		pa(array);
		pa(array);
		pa(array);
	}
}

static void	partitionisthreeb2(t_array *array)
{
	if (array->stackb[1] > array->stackb[0]
		&& array->stackb[1] > array->stackb[2])
	{
		if (array->stackb[0] > array->stackb[2])
			piis3helper(array, 2);
		else
			piis3helper2(array, 3);
	}
	else if (array->stackb[2] > array->stackb[0]
		&& array->stackb[2] > array->stackb[1])
	{
		if (array->stackb[0] > array->stackb[1])
			piis3helper2(array, 4);
		else
			piis3helper3(array, 5);
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
			piis3helper(array, 0);
		else
			piis3helper(array, 1);
	}
	else
		partitionisthreeb2(array);
}
