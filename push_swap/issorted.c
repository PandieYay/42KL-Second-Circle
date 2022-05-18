/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:19:39 by edlim             #+#    #+#             */
/*   Updated: 2022/05/18 14:19:39 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	*makearray(int *arr, int len)
{
	int	*newarr;
	int	i;

	newarr = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		newarr[i] = arr[i];
		i++;
	}
	return (newarr);
}

int	issorted(int *newarr, t_array *array)
{
	int	i;

	i = -1;
	while (++i < array->sizea)
	{
		if (newarr[i] != array->stacka[i])
			return (0);
	}
	return (1);
}

int	bubblesort(int *arr, t_array *array)
{
	int	*newarr;
	int	i;
	int	j;

	i = 0;
	newarr = makearray(arr, array->sizea);
	while (i < array->sizea - 1)
	{
		j = 0;
		while (j < array->sizea - i - 1)
		{
			if (newarr[j] > newarr[j + 1])
				swap(&newarr[j], &newarr[j + 1]);
			j++;
		}
		i++;
	}
	if (issorted(newarr, array) == 1)
	{
		free (newarr);
		return (1);
	}
	free (newarr);
	return (0);
}
