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
#include "checker.h"

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

static int	readtermhelper(char *line, t_array *array)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(array);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(array);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(array);
	else if (ft_strncmp(line, "rra", 3) == 0)
		rra(array);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(array);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(array);
	else
		return (-1);
	return (0);
}

static int	readterm(t_array *array)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strncmp(line, "sa\n", 3) == 0)
			sa(array);
		else if (ft_strncmp(line, "sb\n", 3) == 0)
			sb(array);
		else if (ft_strncmp(line, "ss\n", 3) == 0)
			ss(array);
		else if (ft_strncmp(line, "pa\n", 3) == 0)
			pa(array);
		else if (ft_strncmp(line, "pb\n", 3) == 0)
			pb(array);
		else if (readtermhelper(line, array) == -1)
			return (-1);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
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
	if (readterm(&array) == -1)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	if (bubblesort(array.stacka, &array) == 1 && array.sizeb == 0)
	{
		write (1, "OK\n", 3);
		return (0);
	}
	write (1, "KO\n", 3);
	return (-1);
}

//#include <stdio.h>
// int		i;
// printf("Stacka: ");
// i = -1;
// while (++i < array.sizea)
// 	printf("%d ", array.stacka[i]);
// printf("\nStackb: ");
// i = -1;
// while (++i < array.sizeb)
// 	printf("%d ", array.stackb[i]);