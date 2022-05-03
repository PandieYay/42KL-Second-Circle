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

t_ptrs	getplayercords(t_ptrs param, char *map)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		param.x = 0;
		temp = line;
		while (line[param.x] != '\n' && line[param.x] != '\0')
		{
			if (line[param.x] == 'P')
			{
				free(temp);
				return (param);
			}
			param.x++;
		}
		param.y++;
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
	return (param);
}

static void	moveplayer(t_ptrs param, int x, int y)
{
	mlx_put_image_to_window(param.mlx, param.win, param.empty,
		x * 64, y * 64);
	mlx_put_image_to_window(param.mlx, param.win, param.player,
		param.x * 64, param.y * 64);
}

int	player(int key, t_ptrs *param)
{
	static int	i = 0;
	int			tempx;
	int			tempy;

	tempx = param->x;
	tempy = param->y;
	if (key == 53)
		closewindow(param);
	if (key == 0)
		param->x--;
	if (key == 13)
		param->y--;
	if (key == 1)
		param->y++;
	if (key == 2)
		param->x++;
	if (param->map[param->x][param->y] != '1'
		&& param->map[param->x][param->y] != 'E')
	{
		if (param->map[param->x][param->y] == 'C')
		{
			param->map[param->x][param->y] = '0';
			i++;
		}
		moveplayer(*param, tempx, tempy);
	}
	else if (param->map[param->x][param->y] == 'E' && i == param->coinc)
		closewindow(param);
	else
	{
		param->x = tempx;
		param->y = tempy;
	}
	return (0);
}
