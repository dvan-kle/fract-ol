/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/20 22:51:02 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/06 15:22:07 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1450
# define HEIGHT 1000
# define MAX_ITERATIONS 500

double zoom;

typedef struct s_complex {
	double	real;
	double	imag;

}	t_complex;

typedef struct s_julia {
	double real;
	double imag;
}	t_julia;

typedef struct s_fractol {
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				x;
	int				y;
	int 			set;
	t_julia			*julia;
}	t_fractol;

typedef struct s_hsv {
	double h;
	double s;
	double v;
}	t_hsv;

typedef struct s_rgb {
	int	r;
	int	g;
	int b;
} t_rgb;

int		mandelbrot(t_complex c);
int		julia(t_complex	c, t_julia *julia);
int		iterations(int x, int y, t_complex c, t_fractol *fractol);
void	draw_mandel(mlx_image_t *image, t_fractol *fractol);
int		ft_coloring2(int iterations);
int 	colors(int iterations);
int		check_input(int ac, char **av, t_julia *julia);

#endif