/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:50 by edlim             #+#    #+#             */
/*   Updated: 2022/05/10 21:10:13 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(t_array *array)
{
	int	temp;

	write(1, "sa\n", 3);
	temp = array->stacka[0];
	array->stacka[0] = array->stacka[1];
	array->stacka[1] = temp;
}

void	sb(t_array *array)
{
	int	temp;

	write(1, "sb\n", 3);
	temp = array->stackb[0];
	array->stackb[0] = array->stackb[1];
	array->stackb[1] = temp;
}

void	ss(t_array *array)
{
	int	temp;

	temp = array->stacka[0];
	array->stacka[0] = array->stacka[1];
	array->stacka[1] = temp;
	temp = array->stackb[0];
	array->stackb[0] = array->stackb[1];
	array->stackb[1] = temp;
	write(1, "ss\n", 3);
}

void	pa(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->sizea)
	{
		array->stacka[array->sizea - i] = array->stacka[array->sizea - i - 1];
		i++;
	}
	array->stacka[0] = array->stackb[0];
	array->sizea++;
	i = 0;
	while (i < array->sizeb)
	{
		array->stackb[i] = array->stackb[i + 1];
		i++;
	}
	array->sizeb--;
	write(1, "pa\n", 3);
}

void	pb(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->sizeb)
	{
		array->stackb[array->sizeb - i] = array->stackb[array->sizeb - i - 1];
		i++;
	}
	array->stackb[0] = array->stacka[0];
	array->sizeb++;
	i = 0;
	while (i < array->sizea)
	{
		array->stacka[i] = array->stacka[i + 1];
		i++;
	}
	array->sizea--;
	write(1, "pb\n", 3);
}
