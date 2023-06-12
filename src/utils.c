/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 16:35:06 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/13 00:02:56 by danielvankl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	ft_coloring2(int iterations)
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
	color = r * 0x10000 + 0 * 0x100 + b + 19;
	return (color);
}

void	write_menu(mlx_t *mlx)
{
	mlx_put_string(mlx, "ESC - EXIT", 1200, 60);
	mlx_put_string(mlx, "WASD - CHANGE JULIA", 1200, 80);
	mlx_put_string(mlx, "ARROWS - MOVE AROUND", 1200, 100);
	mlx_put_string(mlx, "SCROLL - ZOOM", 1200, 120);
	mlx_put_string(mlx, "M - RESET MANDELBROT", 1200, 140);
	mlx_put_string(mlx, "J - RESET JULIA", 1200, 160);
}
