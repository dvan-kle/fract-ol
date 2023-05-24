/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 18:06:19 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/05/24 20:02:31 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	t_complex	tmp;
	int			iterations;

	z.real = 0;
	z.imag = 0;
	iterations = 0;
	while (iterations < MAX_ITERATIONS
		&& (z.real * z.real + z.imag * z.imag) < 4)
	{
		tmp.real = z.real * z.real - z.imag * z.imag + c.real;
		tmp.imag = 2 * z.real * z.imag + c.imag;
		z = tmp;
		iterations++;
	}
	return (iterations);
}

int	mandel_iter(int x, int y, t_complex c)
{
	double		x_min;
	double		xy_max;
	double		y_min;
	double		x_step;
	double		y_step;

	x_min = -2.0;
	xy_max = 1.0;
	y_min = -1.0;
	x_step = (xy_max - x_min) / WIDTH;
	y_step = (xy_max - y_min) / HEIGHT;
	c.real = x_min + x * x_step;
	c.imag = xy_max - y * y_step;
	return (mandelbrot(c));
}

int	ft_coloring2(int iterations)
{
	double	t;
	int 	r;
	int 	g;
	int		b;
	int 	color;

	t = (double)iterations / (double)MAX_ITERATIONS;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = r * 0x10000 + g * 0x100 + b;
	return (color);
}

void	ft_mandel(t_fractol *fractol)
{
	t_complex	c;
	int			y;
	int			x;
	int			color;

	y = 0;
	c.real = 0;
	c.imag = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = mandel_iter(x, y, c);
			if (color == MAX_ITERATIONS)
				mlx_put_pixel(fractol->image, x, y, ft_pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(fractol->image, x, y, ft_coloring2(color));
			x++;
		}
		y++;
	}
}

int	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractol->mlx)
		return (exit(-1), EXIT_FAILURE);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
		return (exit(-1), EXIT_FAILURE);
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	mlx_set_window_limit(fractol->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol_init(fractol);
	mlx_loop_hook(fractol->mlx, ft_mandel, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
}

	