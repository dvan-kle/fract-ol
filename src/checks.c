/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 13:36:08 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/07 13:22:00 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	check_julia(char *realstr, char *imagstr, t_julia *julia)
{
	julia->real = atof(realstr);
	julia->imag = atof(imagstr);
	return (0);
}

int	check_input(int ac, char **av, t_julia *julia)
{
	if (ac < 2 || ac > 5)
		return (0);
	if (!ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) && ac == 2)
		return (1);
	if (!ft_strncmp(av[1], "julia", ft_strlen(av[1])) && ac == 4)
	{
		if (!check_julia(av[2], av[3], julia))
			return (2);
	}
	return (0);
}
