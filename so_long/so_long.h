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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_ptrs {
	void	*mlx;
	void	*win;
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

void	ft_putnbr(int n);
void	ft_putstr(char *s);
char	*get_next_line(int fd);
int		checkmap(char *map);
t_ptrs	generatemap(void);

#endif