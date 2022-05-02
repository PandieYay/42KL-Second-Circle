/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointanddestroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:52:06 by edlim             #+#    #+#             */
/*   Updated: 2022/05/02 14:52:07 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*point_image(char *path, t_ptrs param)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(param.mlx, path, &img_w, &img_h);
	return (img);
}

void	destory_images(t_ptrs param)
{
	mlx_destroy_image(param.mlx, param.player);
	mlx_destroy_image(param.mlx, param.coin);
	mlx_destroy_image(param.mlx, param.wall);
	mlx_destroy_image(param.mlx, param.exit);
	mlx_destroy_image(param.mlx, param.empty);
}
