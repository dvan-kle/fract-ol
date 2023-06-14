/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 13:48:35 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 16:03:03 by dvan-kle      ########   odam.nl         */
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
		fractol->shift_x -= 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->shift_x += 0.1;
}

void	ft_switch_hook(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_J))
	{
		fractol->set = 2;
		fractol->shift_x = -0.45;
		fractol->shift_y = 0;
		fractol->zoom = 1.35;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_M))
	{
		fractol->set = 1;
		fractol->shift_x = 0;
		fractol->shift_y = 0;
		fractol->zoom = 1.35;
		fractol->julia->real = 0.0;
		fractol->julia->imag = 0.0;
	}
}
