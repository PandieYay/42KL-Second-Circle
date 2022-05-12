#include "push_swap.h"
#include <stdio.h>

static void swap(int *a, int *b)
{
    int temp;

	temp = *a;
    *a = *b;
    *b = temp;
}

static int *makearray(int *arr, int len)
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
	return(newarr);
}

int	bubblesort(int *arr, int len)
{
	int	median;
	int *newarr;
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
	free(newarr);
	return(median);
}