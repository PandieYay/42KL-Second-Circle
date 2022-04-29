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

t_ptrs	generatemap(void)
{
	t_ptrs	param;
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;

	path = "sprites/64.xpm";
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 384, 192, "mlx 42");
	mlx_pixel_put(param.mlx, param.win, 250, 250, 0xFFFFFF);
	img = mlx_xpm_file_to_image(param.mlx, path, &img_width, &img_height);
	mlx_put_image_to_window (param.mlx, param.win, img, 0, 0);
	mlx_put_image_to_window (param.mlx, param.win, img, 320, 0);
	return (param);
}
