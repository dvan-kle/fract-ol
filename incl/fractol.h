/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/20 22:51:02 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 15:54:22 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1450
# define HEIGHT 1000
# define MAX_ITERATIONS 42

typedef struct s_complex {
	double	real;
	double	imag;

}	t_complex;

typedef struct s_julia {
	double	real;
	double	imag;
}	t_julia;

typedef struct s_fractol {
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				x;
	int				y;
	int				set;
	t_julia			*julia;
	double			zoom;
	double			shift_x;
	double			shift_y;
}	t_fractol;

void	run_fractol(t_fractol *fractol);
void	write_menu(mlx_t *mlx);
void	ft_scroll(double xdelta, double ydelta, void *param);
void	ft_hook(void *param);
void	ft_switch_hook(void *param);
int		mandelbrot(t_complex c);
int		julia(t_complex	c, t_julia *julia);
int		iterations(int x, int y, t_complex c, t_fractol *fractol);
void	draw_mandel(mlx_image_t *image, t_fractol *fractol);
void	error_print(int code);
int		ft_coloring(int iterations);
int		check_input(int ac, char **av, t_julia *julia);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

#endif