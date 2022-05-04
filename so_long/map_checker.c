/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:27:56 by edlim             #+#    #+#             */
/*   Updated: 2022/04/29 13:27:57 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	firstline(int fd)
{
	char	*line;
	int		wallc;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	wallc = 0;
	while (line[wallc] != '\n')
	{
		if (line[wallc] != '1')
			return (-1);
		wallc++;
	}
	free(line);
	return (wallc);
}

static t_map	checkcomponents(char *line, int i, t_map list)
{
	if (line[i] == '1')
		list.wallc++;
	if (line[i] == 'E')
		list.e++;
	if (line[i] == 'C')
		list.c++;
	if (line[i] == 'P')
		list.p++;
	return (list);
}

static t_map	intializevariables(void)
{
	t_map	list;

	list.e = 0;
	list.c = 0;
	list.p = 0;
	list.x = 0;
	list.wallc = 0;
	list.lastwall = 0;
	list.returnnum = 0;
	return (list);
}

static t_map	checklines(char *line, int fd, t_map list)
{
	int	i;

	while (line != NULL)
	{
		if (line[0] != '1')
			list.returnnum = -1;
		i = 1;
		list.wallc = 1;
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
				&& line[i] != 'E' && line[i] != 'P')
				list.returnnum = -1;
			list = checkcomponents(line, i, list);
			if (line[i + 1] == '\n' || line[1 + 1] == '\0')
				if (line[i] != '1')
					list.returnnum = -1;
			i++;
		}
		if (i != list.x)
			list.returnnum = -1;
		free(line);
		line = get_next_line(fd);
	}
	return (list);
}

int	checkmap(char *map)
{
	char	*line;
	int		fd;
	t_map	list;

	list = intializevariables();
	fd = open(map, O_RDONLY);
	list.x = firstline(fd);
	if (list.x == -1)
		return (-1);
	line = get_next_line(fd);
	list = checklines(line, fd, list);
	if (list.returnnum == -1)
		return (-1);
	if (list.wallc == list.x)
		list.lastwall = 1;
	if (list.lastwall != 1 || list.e < 1 || list.c < 1 || list.p != 1)
		return (-1);
	close(fd);
	return (0);
}
