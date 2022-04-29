#include "so_long.h"
#include <stdio.h>

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
	return (wallc);
}

int	checkmap(char *map)
{
	char	*line;
	int		fd;
	int		i;
	int		x;
	int		E;
	int		C;
	int		P;
	int		wallc;
	int		lastwall;

	fd = open(map, O_RDONLY);
	x = firstline(fd);
	if (x == -1)
		return (-1);
	line = get_next_line(fd);
	E = 0;
	C = 0;
	P = 0;
	while (line != NULL)
	{
		lastwall = 0;
		i = 0;
		if (line[i] != '1')
			return (-1);
		i++;
		wallc = 1;
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] == '1')
				wallc++;
			if (line[i] == 'E')
				E++;
			if (line[i] == 'C')
				C++;
			if (line[i] == 'P')
				P++;
			if (line[i + 1] == '\n' || line[1 + 1] == '\0')
			{
				if (line[i] != '1')
					return (-1);
			}
			i++;
		}
		if (i != x)
			return (-1);
		if (wallc == x)
			lastwall = 1;
		line = get_next_line(fd);
	}
	if (lastwall != 1 || E < 1 || C < 1 || P < 1)
		return (-1);
	return (0);
}