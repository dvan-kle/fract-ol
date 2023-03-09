/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 17:47:39 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/03/09 18:12:17 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 5000

static mlx_image_t* image;

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

int mandelbrot(t_complex c) 
{
    t_complex z;
    z.real = 0;
    z.imag = 0;
    int iterations = 0;
    while (iterations < MAX_ITERATIONS && (z.real * z.real + z.imag * z.imag) < 4) {
        t_complex tmp;
        tmp.real = z.real * z.real - z.imag * z.imag + c.real;
        tmp.imag = 2 * z.real * z.imag + c.imag;
        z = tmp;
        iterations++;
    }
    return iterations;
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

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
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int ft_coloring(iterations)
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

	return color;

}

void ft_mandel(void* param)
{
	mlx_t* mlx = param;

	mlx = NULL;
	double x_min = -2.0, x_max = 1.0;
    double y_min = -1.0, y_max = 1.0;
    double x_step = (x_max - x_min) / WIDTH;
    double y_step = (y_max - y_min) / HEIGHT;

    int y = 0;
    while (y < HEIGHT) {
        int x = 0;
        while (x < WIDTH) {
            t_complex c;
            c.real = x_min + x * x_step;
            c.imag = y_max - y * y_step;
			int color = mandelbrot(c);
            if (color == MAX_ITERATIONS) 
			{
				color = ft_pixel(0, 0, 0, 255);
                mlx_put_pixel(image, x, y, color);
            } 
			else 
			{
                int r = 0, g = 122, b = 255;
                if (color < 256) {
                    r = color;
                } else if (color < 512) {
                    r = 255;
                    g = color - 255;
                } else if (color < 768) 
				{
                    r = 255;
                    g = 255;
                    b = color - 512;
                }
				else 
				{
                    r = 255 - (color - 768);
                    g = 255 - (color - 768);
                    b = 255 - (color - 768);
                }
                int color_code = (r << 16) + (g << 8) + b;
                mlx_put_pixel(image, x, y, color_code);
			}
            x++;
        }
        y++;
    }
}

int main() {
   
	mlx_t* mlx;

   if (!(mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true)))
	{
		printf("%s", mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 800, 600)))
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

    mlx_loop_hook(mlx, ft_mandel, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}