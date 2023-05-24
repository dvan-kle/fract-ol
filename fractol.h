/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/20 22:51:02 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/05/24 18:10:03 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 35

typedef struct s_complex {
	double	real;
	double	imag;

}	t_complex;

typedef struct s_fractol {
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				x;
	int				y;
}	t_fractol;

#endif