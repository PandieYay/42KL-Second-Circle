/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:25:17 by edlim             #+#    #+#             */
/*   Updated: 2022/04/29 13:25:18 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	closewindow(t_ptrs *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	key_hook(int key, t_ptrs *param)
{
	if (key == 53)
		closewindow(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ptrs	param;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "sprites/64.xpm";
	if (argc != 2)
		return (-1);
	if (checkmap(argv[1]) == -1)
	{
		ft_putstr("Error\nTest");
		return (-1);
	}
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 384, 192, "mlx 42");
	mlx_pixel_put(param.mlx, param.win, 250, 250, 0xFFFFFF);
	img = mlx_xpm_file_to_image(param.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window (param.mlx, param.win, img, 0, 0);
	mlx_put_image_to_window (param.mlx, param.win, img, 320, 0);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_hook(param.win, 17, 0, &closewindow, &param);
	mlx_loop(param.mlx);
}
