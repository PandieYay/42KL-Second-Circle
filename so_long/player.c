/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:56:02 by edlim             #+#    #+#             */
/*   Updated: 2022/05/01 14:56:03 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	closewindow(t_ptrs *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	player(int key, t_ptrs *param)
{
	if (key == 53)
		closewindow(param);
	if (key == 0)
		write(1, "A", 1);
	if (key == 13)
		write(1, "W", 1);
	if (key == 1)
		write(1, "S", 1);
	if (key == 2)
		write(1, "D", 1);
	return (0);
}
