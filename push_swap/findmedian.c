/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findmedian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:23:22 by edlim             #+#    #+#             */
/*   Updated: 2022/05/16 10:23:23 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	*makearray(int *arr, int len)
{
	int	*newarr;
	int	i;

	newarr = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		newarr[i] = arr[i];
		i++;
	}
	return (newarr);
}

int	bubblesort(int *arr, int len)
{
	int	median;
	int	*newarr;
	int	i;
	int	j;

	i = 0;
	newarr = makearray(arr, len);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (newarr[j] > newarr[j + 1])
				swap(&newarr[j], &newarr[j + 1]);
			j++;
		}
		i++;
	}
	median = newarr[len / 2];
	free (newarr);
	return (median);
}
