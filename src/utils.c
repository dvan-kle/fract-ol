/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 16:35:06 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 15:38:05 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_coloring(int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;

	t = (double)iterations / (double)MAX_ITERATIONS;
	r = (int)(19.2 * (1 - t) * t * t * t * 190);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = r * 0x10000 + g * 0x100 + b + 19;
	return (color);
}

void	write_menu(mlx_t *mlx)
{
	mlx_put_string(mlx, "ESC - EXIT", 1125, 60);
	mlx_put_string(mlx, "WASD - CHANGE JULIA PARAMS", 1125, 80);
	mlx_put_string(mlx, "ARROWS - MOVE CAMERA", 1125, 100);
	mlx_put_string(mlx, "SCROLL - ZOOM", 1125, 120);
	mlx_put_string(mlx, "M - SWITCH TO MANDELBROT", 1125, 140);
	mlx_put_string(mlx, "J - SWITCH TO JULIA", 1125, 160);
}
