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
	array->stacka = malloc(sizeof(int) * i);
	array->stackb = malloc(sizeof(int) * i);
	array->sizea = i;
	array->sizeb = 0;
	i = -1;
	while (argv[++i] != NULL)
		array->stacka[i] = ft_atoi(argv[i]);
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
	else
		quicksort(&array, array.sizea);
	printf("Stacka: ");
	i = -1;
	while (++i < array.sizea)
		printf("%d ", array.stacka[i]);
	printf("\nStackb: ");
	i = -1;
	while (++i < array.sizeb)
		printf("%d ", array.stackb[i]);
}
