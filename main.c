#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 720
#define MAX_ITERATIONS 500

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
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
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

void ft_mandel(void)
{
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
            int iterations = mandelbrot(c);
			int color;
			color = ft_coloring(iterations);
			mlx_put_pixel(image, x, y, color);
            x++;
        }
        y++;
    }
}

void ft_randomize(void)
{
    t_complex	c;
	int			i;
	int			j;
	int			x;
	int			y;

    x = 0;
    y = 0;
    while (x < image->width)
    {
        while (y < image->height)
        {
            int color = ft_pixel(255, 0, 0, 255);
			mlx_put_pixel(image, x, y, color);
            y++;
        }
        x++;
        y = 0;
    }
}


int main() {
   
	mlx_t* mlx;

   if (!(mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 1280, 720)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

    mlx_loop_hook(mlx, ft_mandel, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}