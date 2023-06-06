/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 18:06:19 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/06 15:17:00 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"


void	ft_hook(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	
}

void	ft_zoom(t_fractol *fractol)
{
	mlx_t *mlx = fractol->mlx;
	mlx_image_t	*image = fractol->image;
	
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		zoom = zoom + 0.1;
		draw_mandel(image, 0);
	}
		
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		zoom = zoom - 0.1;
		draw_mandel(image, 0);
	}
		
}

void	fractol_init(mlx_t *mlx, mlx_image_t* image, t_fractol *fractol)
{
	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!mlx)
		return (exit(-1));
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (exit(-1));
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_set_window_limit(mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	draw_mandel(image, fractol);
	//mlx_loop_hook(mlx, &ft_zoom, fractol);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

void leaks_check(void)
{
	system("leaks -s fractol");
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;
	t_julia		*julia;

	zoom = -0.3;
	atexit(leaks_check);
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	julia = (t_julia *)malloc(sizeof(t_julia));
	fractol->set = check_input(ac, av, julia);
	if (!fractol->set)
		exit(EXIT_FAILURE);
	fractol->julia = julia;
	fractol_init(fractol->mlx, fractol->image, fractol);
	free(julia);
	free(fractol);
}

	