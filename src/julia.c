/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 13:21:57 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/08 13:32:16 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

// int julia(t_complex c) {
//     double zr = c.real;
//     double zi = c.imag;
//     int i = 0;
//     while (i < MAX_ITERATIONS && zr * zr + zi * zi < 4) {
//         double new_zr = zr * zr - zi * zi + -0.52;
//         double new_zi = 2 * zr * zi + 0.57;
//         zr = new_zr;
//         zi = new_zi;
//         i++;
//     }
//     return i;
// }

int	julia(t_complex c, t_julia *julia)
{
	t_complex	z;
	t_complex	tmp;
	int			iterations;

	z.real = c.real;
	z.imag = c.imag;
	iterations = 0;
	while (iterations < MAX_ITERATIONS
		&& (z.real * z.real + z.imag * z.imag) < 4)
	{
		tmp.real = z.real * z.real - z.imag * z.imag + julia->real;
		tmp.imag = 2 * z.real * z.imag + julia->imag;
		z = tmp;
		iterations++;
	}
	return (iterations);
}