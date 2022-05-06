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
	if (param->frames >= 56)
		mlx_put_image_to_window(param->mlx, param->win, param->player4,
			param->x * 64, param->y * 64);
	else if (param->frames >= 42)
		mlx_put_image_to_window(param->mlx, param->win, param->player3,
			param->x * 64, param->y * 64);
	else if (param->frames >= 28)
		mlx_put_image_to_window(param->mlx, param->win, param->player2,
			param->x * 64, param->y * 64);
	else if (param->frames >= 14)
		mlx_put_image_to_window(param->mlx, param->win, param->player1,
			param->x * 64, param->y * 64);
	else
		mlx_put_image_to_window(param->mlx, param->win, param->player,
			param->x * 64, param->y * 64);
}

static void	putcoinanimation(t_ptrs *param, int i, int k)
{
	mlx_put_image_to_window(param->mlx, param->win, param->empty,
		i * 64, k * 64);
	if (param->frames >= 54)
		mlx_put_image_to_window(param->mlx, param->win, param->coin3,
			i * 64, k * 64);
	else if (param->frames >= 36)
		mlx_put_image_to_window(param->mlx, param->win, param->coin2,
			i * 64, k * 64);
	else if (param->frames >= 18)
		mlx_put_image_to_window(param->mlx, param->win, param->coin1,
			i * 64, k * 64);
	else
		mlx_put_image_to_window(param->mlx, param->win, param->coin,
			i * 64, k * 64);
}

void	coinanimation(t_ptrs *param)
{
	int	i;
	int	k;

	i = -1;
	while (param->map[++i] != NULL)
	{
		k = 0;
		while (param->map[i][k] != '\0' && param->map[i][k] != '\n')
		{
			if (param->map[i][k] == 'C')
				putcoinanimation(param, i, k);
			k++;
		}
	}
}
