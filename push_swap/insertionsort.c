#include "push_swap.h"

void	insertionsortb(t_array *array, int n)
{
	int	i;
	int	k;

	i = 1;
	while (i < n)
	{
		k = i - 1;
		while (k >= 0 && array->stackb[i] > array->stackb[k])
		{
			if (array->stackb[1] > array->stackb[0])
				sb(array);
			else
				rrb(array);
			k = k - 1;
		}
		if (array->stackb[1] > array->stackb[0])
			sb(array);
		i++;
	}
}