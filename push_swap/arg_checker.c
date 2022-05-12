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

static int	checkint(char *arg)
{
	int	i;

	i = 0;
	while (*arg != '\0')
	{
		if (*arg == '+' || *arg == '-')
			i++;
		if (!(*arg >= '0' && *arg <= '9'))
		{
			if (*arg != '+' && *arg != '-')
			{
				write(1, "Error\n", 6);
				return (-1);
			}
		}
		arg++;
	}
	if (i > 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	checkarg(char **argv)
{
	int	i;
	int	k;

	i = -1;
	while (argv[++i] != NULL)
	{
		k = i;
		if (checkint(argv[i]) == -1)
			return (-1);
		if (ft_atoi(argv[i]) == -1)
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
