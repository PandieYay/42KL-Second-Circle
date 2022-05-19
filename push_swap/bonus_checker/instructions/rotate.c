/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotinstructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:50 by edlim             #+#    #+#             */
/*   Updated: 2022/05/10 20:47:12 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_array *array)
{
	int		i;
	int		temp;

	temp = array->stacka[0];
	i = 0;
	while (i < array->sizea - 1)
	{
		array->stacka[i] = array->stacka[i + 1];
		i++;
	}
	array->stacka[i] = temp;
}

void	rb(t_array *array)
{
	int		i;
	int		temp;

	temp = array->stackb[0];
	i = 0;
	while (i < array->sizeb - 1)
	{
		array->stackb[i] = array->stackb[i + 1];
		i++;
	}
	array->stackb[i] = temp;
}

void	rr(t_array *array)
{
	int		i;
	int		temp;

	temp = array->stacka[0];
	i = 0;
	while (i < array->sizea - 1)
	{
		array->stacka[i] = array->stacka[i + 1];
		i++;
	}
	array->stacka[i] = temp;
	temp = array->stackb[0];
	i = 0;
	while (i < array->sizeb - 1)
	{
		array->stackb[i] = array->stackb[i + 1];
		i++;
	}
	array->stackb[i] = temp;
}
