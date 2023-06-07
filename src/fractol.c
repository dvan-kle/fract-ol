/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 18:06:19 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/07 20:58:25 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_hook(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		printf("HOOK WORKING\n");
}

void	ft_hook2(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	draw_mandel(fractol->image, fractol);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->zoom += 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->zoom -= 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_A))
		fractol->julia->imag -= 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_D))
		fractol->julia->imag += 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_W))
		fractol->julia->real += 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_S))
		fractol->julia->real -= 0.03;
}

void	ft_zoom(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
	{
		fractol->zoom += 0.1;
		draw_mandel(fractol->image, fractol);
	}
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// {
	// 	fractol2->zoom = fractol2->zoom - 0.1;
	// 	draw_mandel(fractol->image, fractol2);
	// }
}

// void	fractol_init(mlx_t *mlx, mlx_image_t *image, t_fractol *fractol)
// {
// 	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
// 	if (!mlx)
// 		return (exit(-1));
// 	image = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!image)
// 		return (exit(-1));
// 	mlx_image_to_window(mlx, image, 0, 0);
// 	mlx_set_window_limit(mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
// 	draw_mandel(image, fractol);
// 	mlx_loop_hook(mlx, ft_zoom, fractol);
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// }

void	fractol_init2(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!fractol->mlx)
		return (exit(-1));
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
		return (exit(-1));
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	mlx_set_window_limit(fractol->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	// draw_mandel(fractol->image, fractol);
	//mlx_loop_hook(fractol->mlx, ft_zoom, fractol);
	mlx_loop_hook(fractol->mlx, ft_hook2, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
}

void	leaks_check(void)
{
	system("leaks -s fractol");
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	atexit(leaks_check);
	fractol.julia = (t_julia *)malloc(sizeof(t_julia));
	fractol.set = check_input(ac, av, fractol.julia);
	fractol.zoom = -0.45;
	if (!fractol.set)
		exit(EXIT_FAILURE);
	// fractol_init(fractol.mlx, fractol.fractol->image, &fractol);
	fractol_init2(&fractol);
	free(fractol.julia);
}
