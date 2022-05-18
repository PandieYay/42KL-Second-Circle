/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:46:31 by edlim             #+#    #+#             */
/*   Updated: 2022/05/09 15:46:33 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkarg(char **argv)
{
	int	i;
	int	k;

	i = -1;
	while (argv[++i] != NULL)
	{
		k = i;
		if (ft_atoichecker(argv[i]) == 'K')
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		while (argv[k + 1] != NULL)
		{
			if (ft_strcmp(argv[i], argv[k + 1]) == 0)
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			k++;
		}
	}
	return (0);
}
