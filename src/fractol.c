/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 18:06:19 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/11 17:10:58 by danielvankl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = param;

	if (ydelta > 0)
		fractol->zoom *= 1.1;
	if (ydelta < 0)
		fractol->zoom *= 0.9;
	xdelta = 0;
}


void	ft_hook(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	draw_mandel(fractol->image, fractol);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_A))
		fractol->julia->imag -= 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_D))
		fractol->julia->imag += 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_W))
		fractol->julia->real += 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_S))
		fractol->julia->real -= 0.03;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->shift_y -= 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->shift_y += 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->shift_x += 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->shift_x -= 0.1;
}

void	run_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!fractol->mlx)
		return (exit(-1));
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
		return (exit(-1));
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	mlx_set_window_limit(fractol->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	mlx_scroll_hook(fractol->mlx, ft_scroll, fractol);
	mlx_loop_hook(fractol->mlx, ft_hook, fractol);
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

	// atexit(leaks_check);
	fractol.julia = (t_julia *)malloc(sizeof(t_julia));
	if (!fractol.julia)
		return (error_print(1), EXIT_FAILURE);
	fractol.set = check_input(ac, av, fractol.julia);
	if (!fractol.set)
		return (error_print(0), EXIT_FAILURE);
	fractol.zoom = 1.0;
	fractol.shift_x = 0;
	if (fractol.set == 2)
		fractol.shift_x = -0.45;
	fractol.shift_y = 0;
	run_fractol(&fractol);
	free(fractol.julia);
}
