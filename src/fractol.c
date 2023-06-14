/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 18:06:19 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 15:48:48 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	run_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!fractol->mlx)
		return (free(fractol->julia), error_print(2));
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
		return (free(fractol->julia), error_print(2));
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	mlx_set_window_limit(fractol->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	write_menu(fractol->mlx);
	mlx_scroll_hook(fractol->mlx, ft_scroll, fractol);
	mlx_loop_hook(fractol->mlx, ft_hook, fractol);
	mlx_loop_hook(fractol->mlx, ft_switch_hook, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.julia = (t_julia *)malloc(sizeof(t_julia));
	if (!fractol.julia)
		return (error_print(1), EXIT_FAILURE);
	fractol.set = check_input(ac, av, fractol.julia);
	if (!fractol.set)
		return (error_print(0), EXIT_FAILURE);
	fractol.zoom = 1.35;
	fractol.shift_x = 0;
	if (fractol.set == 2)
		fractol.shift_x = -0.45;
	fractol.shift_y = 0;
	run_fractol(&fractol);
	free(fractol.julia);
}
