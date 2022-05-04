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

static t_ptrs	*moveplayer(t_ptrs *param, int x, int y)
{
	param->movement++;
	mlx_put_image_to_window(param->mlx, param->win, param->wall,
		1 * 64, 0);
	mlx_put_image_to_window(param->mlx, param->win, param->empty,
		x * 64, y * 64);
	mlx_put_image_to_window(param->mlx, param->win, param->player,
		param->x * 64, param->y * 64);
	mlx_string_put(param->mlx, param->win, 75, 0, 0xFFFF,
		ft_itoa(param->movement));
	param->map[x][y] = '0';
	param->map[param->x][param->y] = 'P';
	return (param);
}

static t_ptrs	*checkparam(int key, t_ptrs *param)
{
	if (key == 0)
		param->x--;
	if (key == 13)
		param->y--;
	if (key == 1)
		param->y++;
	if (key == 2)
		param->x++;
	return (param);
}

static t_ptrs	*keypressed(t_ptrs *param, int key, int tempx, int tempy)
{
	static int	i = 0;

	param = checkparam(key, param);
	if (param->map[param->x][param->y] != '1'
		&& param->map[param->x][param->y] != 'E')
	{
		if (param->map[param->x][param->y] == 'B')
			closewindow(param);
		if (param->map[param->x][param->y] == 'C')
			i++;
		param = moveplayer(param, tempx, tempy);
	}
	else if (param->map[param->x][param->y] == 'E' && i == param->coinc)
		closewindow(param);
	else
	{
		param->x = tempx;
		param->y = tempy;
	}
	return (param);
}

int	player(int key, t_ptrs *param)
{
	int	tempx;
	int	tempy;

	tempx = param->x;
	tempy = param->y;
	if (key == 53)
		closewindow(param);
	if (key == 0 || key == 13 || key == 1 || key == 2)
		param = keypressed(param, key, tempx, tempy);
	else if (param->enemythere == 1)
		enemy(key, param);
	return (0);
}
