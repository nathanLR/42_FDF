#include <stdio.h>
#include "MacroLibX/includes/mlx.h"

int	key_hook(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx);
	return (0);
}

int	mouse_wheel(int button, void *mlx)
{
	(void)mlx;
	printf("%d\n", button);
	return (0);
}
int	mouse_down(int button, void *mlx)
{
	(void)mlx;
	printf("%d\n", button);
	return (0);
}

int	main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 400, 400, "test");
	
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx, win, MLX_MOUSEDOWN, mouse_down, NULL);
	mlx_on_event(mlx, win, MLX_MOUSEWHEEL, mouse_wheel, NULL);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			mlx_pixel_put(mlx, win, i, j, 0xffff0000);
		}
	}
mlx_loop(mlx);


	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	return (0);
}
