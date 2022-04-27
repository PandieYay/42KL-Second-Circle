#include "mlx.h"
#include "so_long.h"

int	closewindow(ptrs *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	key_hook(int key, ptrs *param)
{
	if(key == 53)
		closewindow(param);
	return (0);
}

int	main(void)
{
	ptrs	param;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx 42");
	mlx_pixel_put(param.mlx, param.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_hook(param.win, 17, 0, &closewindow, &param);
	mlx_loop(param.mlx);
}