/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:25:17 by edlim             #+#    #+#             */
/*   Updated: 2022/04/29 13:25:18 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	closewindow(t_ptrs *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_ptrs	param;
	char	*path;

	path = "sprites/64.xpm";
	if (argc != 2)
		return (-1);
	if (checkmap(argv[1]) == -1)
	{
		ft_putstr("Error\nIncorrect Map");
		return (-1);
	}
	param = generatemap(argv[1]);
	param = getplayercords(param, argv[1]);
	mlx_hook(param.win, 2, 0, &player, &param);
	mlx_hook(param.win, 17, 0, &closewindow, &param);
	mlx_loop(param.mlx);
}
