/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmedian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:10:21 by edlim             #+#    #+#             */
/*   Updated: 2022/05/19 18:10:22 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortmedian(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->sizea)
	{
		if (array->stacka[i] < array->median)
			return (1);
		i++;
	}
	return (0);
}

int	sortmedianb(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->sizeb)
	{
		if (array->stackb[i] >= array->median)
			return (1);
		i++;
	}
	return (0);
}
