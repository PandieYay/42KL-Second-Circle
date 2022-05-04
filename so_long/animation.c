/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:31:41 by edlim             #+#    #+#             */
/*   Updated: 2022/05/04 16:31:43 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemyanimation(t_ptrs *param)
{
	mlx_put_image_to_window(param->mlx, param->win, param->empty,
		param->enemyx * 64, param->enemyy * 64);
	if (param->frames >= 60)
		mlx_put_image_to_window(param->mlx, param->win, param->enemy6,
			param->enemyx * 64, param->enemyy * 64);
	else if (param->frames >= 50)
		mlx_put_image_to_window(param->mlx, param->win, param->enemy5,
			param->enemyx * 64, param->enemyy * 64);
	else if (param->frames >= 40)
		mlx_put_image_to_window(param->mlx, param->win, param->enemy4,
			param->enemyx * 64, param->enemyy * 64);
	else if (param->frames >= 30)
		mlx_put_image_to_window(param->mlx, param->win, param->enemy3,
			param->enemyx * 64, param->enemyy * 64);
	else if (param->frames >= 20)
		mlx_put_image_to_window(param->mlx, param->win, param->enemy2,
			param->enemyx * 64, param->enemyy * 64);
	else if (param->frames >= 10)
		mlx_put_image_to_window(param->mlx, param->win, param->enemy1,
			param->enemyx * 64, param->enemyy * 64);
	else
		mlx_put_image_to_window(param->mlx, param->win, param->enemy,
			param->enemyx * 64, param->enemyy * 64);
}

void	playeranimation(t_ptrs *param)
{
	mlx_put_image_to_window(param->mlx, param->win, param->empty,
		param->x * 64, param->y * 64);
	if (param->frames >= 60)
		mlx_put_image_to_window(param->mlx, param->win, param->player5,
			param->x * 64, param->y * 64);
	else if (param->frames >= 50)
		mlx_put_image_to_window(param->mlx, param->win, param->player4,
			param->x * 64, param->y * 64);
	else if (param->frames >= 40)
		mlx_put_image_to_window(param->mlx, param->win, param->player3,
			param->x * 64, param->y * 64);
	else if (param->frames >= 30)
		mlx_put_image_to_window(param->mlx, param->win, param->player2,
			param->x * 64, param->y * 64);
	else if (param->frames >= 20)
		mlx_put_image_to_window(param->mlx, param->win, param->player1,
			param->x * 64, param->y * 64);
	else
		mlx_put_image_to_window(param->mlx, param->win, param->player,
			param->x * 64, param->y * 64);
}
