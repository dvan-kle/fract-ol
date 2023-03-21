/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 17:47:39 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/03/21 16:58:42 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 35

static mlx_image_t* image;
static mlx_image_t* background;
static float zoom;

typedef struct s_complex {
	double	real;
	double	imag;

}	t_complex;

int julia_iterations(t_complex c) {
    double zr = c.real;
    double zi = c.imag;
    int i = 0;
    while (i < MAX_ITERATIONS && zr * zr + zi * zi < 4) {
        double new_zr = zr * zr - zi * zi + -0.8;
        double new_zi = 2 * zr * zi + 0.156;
        zr = new_zr;
        zi = new_zi;
        i++;
    }
    return i;
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
	x_step = (xy_max - x_min) / (WIDTH * zoom);
	y_step = (xy_max - y_min) / (HEIGHT * zoom);
	c.real = x_min + x * x_step;
	c.imag = xy_max - y * y_step;
	return (julia_iterations(c));
}

void ft_background(void *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y += 25;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y -= 25;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x += 25;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x -= 25;
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

void	ft_mandel(void *param)
{
	t_complex	c;
	int			y;
	int			x;
	int			color;
	mlx_t		*mlx;

	y = 0;
	c.real = 0;
	c.imag = 0;
	mlx = param;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = mandel_iter(x, y, c);
			if (color == MAX_ITERATIONS)
				mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(image, x, y, ft_coloring2(color));
			x++;
		}
		y++;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_EQUAL))
	{
		zoom *= 2;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_MINUS))
	{
		zoom *= 0.5;
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
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
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
	background = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_set_window_limit(mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	mlx_loop_hook(mlx, ft_background, mlx);
	mlx_loop_hook(mlx, ft_mandel, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}