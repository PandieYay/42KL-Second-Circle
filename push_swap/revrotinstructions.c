/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotinstructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:50 by edlim             #+#    #+#             */
/*   Updated: 2022/05/10 20:48:59 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_array *array)
{
	int		i;
	char	*temp;

	temp = array->stacka[array->sizea - 1];
	i = 1;
	while (i < array->sizea)
	{
		array->stacka[array->sizea - i] = array->stacka[array->sizea - i - 1];
		i++;
	}
	array->stacka[array->sizea - i] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_array *array)
{
	int		i;
	char	*temp;

	temp = array->stackb[array->sizeb - 1];
	i = 1;
	while (i < array->sizeb)
	{
		array->stackb[array->sizeb - i] = array->stackb[array->sizeb - i - 1];
		i++;
	}
	array->stackb[array->sizeb - i] = temp;
	write(1, "rra\n", 4);
}

void	rrr(t_array *array)
{
	int		i;
	char	*temp;

	temp = array->stacka[array->sizea - 1];
	i = 1;
	while (i < array->sizea)
	{
		array->stacka[array->sizea - i] = array->stacka[array->sizea - i - 1];
		i++;
	}
	array->stacka[array->sizea - i] = temp;
	temp = array->stackb[array->sizeb - 1];
	i = 1;
	while (i < array->sizeb)
	{
		array->stackb[array->sizeb - i] = array->stackb[array->sizeb - i - 1];
		i++;
	}
	array->stackb[array->sizeb - i] = temp;
	write(1, "rrr\n", 4);
}
