/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:49:48 by edlim             #+#    #+#             */
/*   Updated: 2022/04/29 16:49:50 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_mapsize	getmapsize(char *map)
{
	t_mapsize	mapsize;
	char		*line;
	int			fd;

	mapsize.x = 0;
	mapsize.y = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line[mapsize.x] != '\n')
		mapsize.x++;
	mapsize.y++;
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		mapsize.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (mapsize);
}

static void	checkcomponents(char *line, t_mapsize mapsize, t_ptrs param)
{
	void	*img;

	if (line[mapsize.x] == '1')
		img = param.wall;
	if (line[mapsize.x] == 'E')
		img = param.exit;
	if (line[mapsize.x] == 'C')
		img = param.coin;
	if (line[mapsize.x] == 'P')
		img = param.player;
	if (line[mapsize.x] == '0')
		img = NULL;
	if (img != NULL)
	{
		mlx_put_image_to_window(param.mlx, param.win, img,
			mapsize.x * 64, mapsize.y * 64);
	}
}

static t_ptrs	initializeimages(t_ptrs param)
{
	param.player = point_image("sprites/player.xpm", param);
	param.coin = point_image("sprites/coin.xpm", param);
	param.wall = point_image("sprites/wall.xpm", param);
	param.exit = point_image("sprites/exit.xpm", param);
	param.empty = point_image("sprites/empty.xpm", param);
	return (param);
}

static void	initializemap(t_ptrs param, t_mapsize mapsize, char *map)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	mapsize.y = 0;
	while (line != NULL)
	{
		mapsize.x = 0;
		temp = line;
		while (line[mapsize.x] != '\n' && line[mapsize.x] != '\0')
		{
			checkcomponents(line, mapsize, param);
			param.map[mapsize.x][mapsize.y] = line[mapsize.x];
			mapsize.x++;
		}
		mapsize.y++;
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
}

t_ptrs	generatemap(char *map)
{
	t_ptrs		param;
	t_mapsize	mapsize;
	int			i;

	mapsize = getmapsize(map);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, mapsize.x * 64,
			mapsize.y * 64, "./so_long");
	param.map = malloc(sizeof(char *) * mapsize.x + 1);
	i = -1;
	while (++i < mapsize.x)
		param.map[i] = malloc(sizeof(char) * mapsize.y);
	param.map[mapsize.x] = NULL;
	param = initializeimages(param);
	initializemap(param, mapsize, map);
	return (param);
}
