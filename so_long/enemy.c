/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:06:46 by edlim             #+#    #+#             */
/*   Updated: 2022/05/04 14:06:47 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ptrs	getenemycords(t_ptrs param, char *map)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		param.enemyx = 0;
		temp = line;
		while (line[param.enemyx] != '\n' && line[param.enemyx] != '\0')
		{
			if (line[param.enemyx] == 'B')
			{
				free(temp);
				return (param);
			}
			param.enemyx++;
		}
		param.enemyy++;
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
	return (param);
}

static t_ptrs	*moveenemy(t_ptrs *param, int x, int y)
{
	mlx_put_image_to_window(param->mlx, param->win, param->empty,
		x * 64, y * 64);
	mlx_put_image_to_window(param->mlx, param->win, param->enemy,
		param->enemyx * 64, param->enemyy * 64);
	param->map[x][y] = '0';
	param->map[param->enemyx][param->enemyy] = 'B';
	return (param);
}

static t_ptrs	*checkparam(int key, t_ptrs *param)
{
	if (key == 123)
		param->enemyx--;
	if (key == 126)
		param->enemyy--;
	if (key == 125)
		param->enemyy++;
	if (key == 124)
		param->enemyx++;
	return (param);
}

static t_ptrs	*keypressed(t_ptrs *param, int key, int tempx, int tempy)
{
	param = checkparam(key, param);
	if (param->map[param->enemyx][param->enemyy] != '1'
		&& param->map[param->enemyx][param->enemyy] != 'E'
			&& param->map[param->enemyx][param->enemyy] != 'C')
	{
		if (param->map[param->enemyx][param->enemyy] == 'P')
			closewindow(param);
		param = moveenemy(param, tempx, tempy);
	}
	else
	{
		param->enemyx = tempx;
		param->enemyy = tempy;
	}
	return (param);
}

void	enemy(int key, t_ptrs *param)
{
	int	tempx;
	int	tempy;

	tempx = param->enemyx;
	tempy = param->enemyy;
	if (key == 123 || key == 124 || key == 125 || key == 126)
		keypressed(param, key, tempx, tempy);
}
