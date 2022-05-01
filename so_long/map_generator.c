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

#include "mlx.h"
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

static void	initializexpm(t_ptrs param, t_mapsize mapsize, char *path)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(param.mlx, path, &img_w, &img_h);
	mlx_put_image_to_window(param.mlx, param.win, img,
		mapsize.x * 64, mapsize.y * 64);
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
			if (line[mapsize.x] == '1')
				initializexpm(param, mapsize, "sprites/64.xpm");
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

	mapsize = getmapsize(map);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, mapsize.x * 64,
			mapsize.y * 64, "./so_long");
	initializemap(param, mapsize, map);
	return (param);
}
