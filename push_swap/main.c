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
	while (argv[i] != NULL)
		i++;
	array->stacka = malloc(sizeof(char *) * i);
	array->stackb = malloc(sizeof(char *) * i);
	array->sizea = i;
	array->sizeb = 0;
	i = -1;
	while (argv[++i] != NULL)
		array->stacka[i] = ft_atoi(argv[i]);
}

// static void swap(int *a, int *b)
// {
//     int temp;

// 	temp = *a;
//     *a = *b;
//     *b = temp;
// }

// static int	partition(t_array array, int low, int high)
// {
// 	int	pivot;
// 	int	i;
// 	int	k;

// 	pivot = array.stacka[high];
// 	i = (low - 1);
// 	k = low;
// 	while (k < high)
// 	{
// 		if (array.stacka[k] < pivot)
// 		{
// 			i++;
// 			swap(&array.stacka[i], &array.stacka[k]);
// 		}
// 		k++;
// 	}
// 	swap(&array.stacka[i + 1], &array.stacka[high]);
// 	return (i + 1);
// }

// static void	quicksort(t_array array, int low, int high)
// {
// 	int	pi;

// 	if (low < high)
// 	{
// 		pi = partition(array, low, high);
// 		quicksort(array, low, pi - 1);
// 		quicksort(array, pi + 1, high);
// 	}
// }

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

static void	rmout(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		argv[i] = argv[i + 1];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_array	array;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		rmout(argv);
	if (checkarg(argv) == -1)
		return (-1);
	fillstacks(argv, &array);
	if (array.sizea <= 3)
		insertionsort(&array, array.sizea);
	i = -1;
	while (++i < array.sizea)
		printf("%d", array.stacka[i]);
}
