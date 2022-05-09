/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:50 by edlim             #+#    #+#             */
/*   Updated: 2022/05/09 17:45:51 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**sa(char **argv)
{
	char	*temp;

	temp = argv[0];
	argv[0] = argv[1];
	argv[1] = temp;
	write(1, "sa\n", 3);
	return (argv);
}

char	**ra(char **argv)
{
	int		i;
	char	*temp;

	i = 0;
	temp = argv[i];
	while (argv[i] != NULL && argv[i + 1] != NULL)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argv[i] = temp;
	write(1, "ra\n", 3);
	return (argv);
}
