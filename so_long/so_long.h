/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:28:30 by edlim             #+#    #+#             */
/*   Updated: 2022/04/29 13:28:31 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_ptrs {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		enemyx;
	int		enemyy;
	int		enemythere;
	int		movement;
	int		frames;
	int		coinc;
	char	**map;
	void	*player;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*player5;
	void	*coin;
	void	*wall;
	void	*exit;
	void	*empty;
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*enemy5;
	void	*enemy6;
}	t_ptrs;

typedef struct s_map {
	int	e;
	int	c;
	int	p;
	int	x;
	int	wallc;
	int	lastwall;
	int	returnnum;
}	t_map;

typedef struct s_mapsize {
	int	x;
	int	y;
}	t_mapsize;

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	*point_image(char *path, t_ptrs param);
void	destory_images(t_ptrs param);
void	enemy(int key, t_ptrs *param);
void	enemyanimation(t_ptrs *param);
void	playeranimation(t_ptrs *param);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
int		player(int key, t_ptrs *param);
int		checkmap(char *map);
int		closewindow(t_ptrs *param);
t_ptrs	generatemap(char *map);
t_ptrs	getplayercords(t_ptrs param, char *map);
t_ptrs	getenemycords(t_ptrs param, char *map);

#endif