/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 17:47:39 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/03/11 22:44:04 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 500

static mlx_image_t* image;
static double zoom;

typedef struct s_complex {
	double	real;
	double	imag;

}	t_complex;

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

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 100;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 100;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 100;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 100;
	if (mlx_is_key_down(mlx, MLX_KEY_EQUAL))
	{
		zoom += 0.2;
		image = mlx_new_image(mlx, (800 * zoom) , (600 * zoom));
		mlx_image_to_window(mlx, image, 0, 0);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_MINUS))
	{
		zoom -= 0.2;
		image = mlx_new_image(mlx, (800 * zoom) , (600 * zoom));
		mlx_image_to_window(mlx, image, 0, 0);
	}
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_coloring(int iterations)
{
	int	color;

	if (iterations >= 0 && iterations < 100)
		color = ft_pixel(255, 229, 59, 255);
	if (iterations >= 100 && iterations < 300)
		color = ft_pixel(255, 116, 0, 255);
	if (iterations >= 300 && iterations < 500)
		color = ft_pixel(255, 0, 0, 255);
	if (iterations >= 500 && iterations < 700)
		color = ft_pixel(133, 0, 0, 255);
	if (iterations >= 700 && iterations < 1000)
		color = ft_pixel(63, 0, 0, 255);
	if (iterations == MAX_ITERATIONS)
		color = ft_pixel(0, 0, 0, 255);
	return (color);
}

void	ft_mandel(void *param)
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
				mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(image, x, y, ft_coloring(color));
			x++;
		}
		y++;
	}
}

int	main(void)
{
	mlx_t* mlx;
	zoom = 1;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true)))
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, (800 * 2), (600 * 2))))
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_mandel, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_put_string(mlx, "MANDELBROT bitch", WIDTH / 2, HEIGHT / 2);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}