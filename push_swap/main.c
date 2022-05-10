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
	array->stacka = malloc(sizeof(char *) * (i + 1));
	array->stacka[i] = NULL;
	array->stackb = malloc(sizeof(char *) * (i + 1));
	array->stackb[i] = NULL;
	array->sizea = i;
	array->sizeb = 0;
	i = 0;
	while (argv[++i] != NULL)
		array->stacka[i - 1] = argv[i];
}

// static void sortstack(char **stacka)
// {
// 	int	i;

// 	i = 0;
// 	while (stacka[i + 1] != NULL)
// 		i++;
// 	if (ft_atoi(stacka[0]) > ft_atoi(stacka[i]))
// 		stacka = ra(stacka);
// 	else if (ft_atoi(stacka[0]) > ft_atoi(stacka[1]))
// 		stacka = swap(stacka, 'a');
// 	else if (ft_atoi(stacka[i]) > ft_atoi(stacka[0]))
// 		stacka = rra(stacka);
// }

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
	pb(&array);
	pb(&array);
	pa(&array);
	i = -1;
	while (++i < 4)
		printf("%s", array.stacka[i]);
}
