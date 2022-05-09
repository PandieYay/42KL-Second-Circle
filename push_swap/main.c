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

static char	**checktop(char **stack)
{
	int	top;
	int	secondelem;
	int	swap;

	swap = 0;
	top = ft_atoi(stack[0]);
	secondelem = ft_atoi(stack[1]);
	if (top > secondelem)
		swap = 1;
	if (swap == 1)
		stack = sa(stack);
	return (stack);
}

static char	**checklast(char **stack)
{
	int	i;
	int	top;
	int	lastelem;
	int	swap;

	i = 0;
	swap = 0;
	top = ft_atoi(stack[0]);
	while (stack[i + 1] != NULL)
		i++;
	lastelem = ft_atoi(stack[i]);
	if (top > lastelem)
		swap = 1;
	if (swap == 1)
		stack = ra(stack);
	return (stack);
}

static char	**fillstacka(char **argv)
{
	int		i;
	char	**stacka;

	i = 0;
	while (argv[i + 1] != NULL)
		i++;
	stacka = malloc(sizeof(char *) * i);
	stacka[i - 1] = NULL;
	i = 0;
	while (argv[++i] != NULL)
		stacka[i - 1] = argv[i];
	return (stacka);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**stacka;

	if (argc < 2)
		return (-1);
	if (checkarg(argv) == -1)
		return (-1);
	stacka = fillstacka(argv);
	if (argc >= 3)
	{
		stacka = checklast(stacka);
		stacka = checktop(stacka);
	}
	i = -1;
	while (stacka[++i] != NULL)
		printf("%s", stacka[i]);
	free(stacka);
}
