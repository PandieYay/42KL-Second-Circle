#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	ft_putnbr(int n);
void	ft_putstr(char *s);
char	*get_next_line(int fd);
int		checkmap(char *map);

typedef struct ptrs {
	void	*mlx;
	void	*win;
}	t_ptrs;

#endif