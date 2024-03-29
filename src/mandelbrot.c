/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 16:38:07 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 15:39:29 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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

int	iterations(int x, int y, t_complex c, t_fractol *fractol)
{
	double		x_min;
	double		xy_max;
	double		y_min;
	double		x_step;
	double		y_step;

	x_min = -2.0;
	xy_max = 1.0;
	y_min = -1.0;
	x_step = (xy_max - x_min) / (WIDTH);
	y_step = (xy_max - y_min) / (HEIGHT);
	c.real = (x_min + x * x_step - fractol->shift_x) * fractol->zoom;
	c.imag = (xy_max - y * y_step - fractol->shift_y) * fractol->zoom;
	if (fractol->set == 1)
		return (mandelbrot(c));
	if (fractol->set == 2)
		return (julia(c, fractol->julia));
	return (0);
}

void	draw_mandel(mlx_image_t *image, t_fractol *fractol)
{
	t_complex	c;
	int			y;
	int			x;
	int			iters;

	y = 0;
	c.real = 0;
	c.imag = 0;
	while (y < (HEIGHT + fractol->shift_y))
	{
		x = 0;
		while (x < (WIDTH + fractol->shift_x))
		{
			iters = iterations(x, y, c, fractol);
			if (iters == MAX_ITERATIONS)
				mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(image, x, y, ft_coloring(iters));
			x++;
		}
		y++;
	}
}
