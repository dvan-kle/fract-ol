/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 13:21:57 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 15:50:52 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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
		tmp.real = z.real * z.real - z.imag * z.imag + -(julia->real);
		tmp.imag = 2 * z.real * z.imag + julia->imag;
		z = tmp;
		iterations++;
	}
	return (iterations);
}
