/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:02:48 by edlim             #+#    #+#             */
/*   Updated: 2022/05/09 11:02:49 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

static void	fillstacks(char **argv, t_array *array)
{
	int		i;

	i = 0;
	while (argv[i + 1] != NULL)
		i++;
	array->stacka = malloc(sizeof(char *) * i);
	array->stackb = malloc(sizeof(char *) * i);
	array->sizea = i;
	array->sizeb = 0;
	i = 0;
	while (argv[++i] != NULL)
		array->stacka[i - 1] = ft_atoi(argv[i]);
}

static void swap(int *a, int *b)
{
    int temp;

	temp = *a;
    *a = *b;
    *b = temp;
}

static int	partition(t_array array, int low, int high)
{
	int	pivot;
	int	i;
	int	k;

	pivot = array.stacka[high];
	i = (low - 1);
	k = low;
	while (k < high)
	{
		if (array.stacka[k] < pivot)
		{
			i++;
			swap(&array.stacka[i], &array.stacka[k]);
		}
		k++;
	}
	swap(&array.stacka[i + 1], &array.stacka[high]);
	return (i + 1);
}

static void	quicksort(t_array array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_array	array;

	if (argc < 2)
		return (-1);
	if (checkarg(argv) == -1)
		return (-1);
	fillstacks(argv, &array);
	// if (argc >= 3)
	quicksort(array, 0, array.sizea - 1);
	i = -1;
	while (++i < array.sizea)
		printf("%d", array.stacka[i]);
}
