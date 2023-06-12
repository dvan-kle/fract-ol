/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 13:36:08 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/13 00:18:07 by danielvankl   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	error_print(int code)
{
	if (code == 0)
	{
		ft_printf("\nInvalid input\n\nRun as following:\n");
		ft_printf("- ./fractol mandelbrot\n");
		ft_printf("- ./fractol julia @param @param\n");
		ft_printf("   @param should be a float between -1 and 1\n\n");
	}
	if (code == 1)
		ft_printf("Malloc failed\n");
	if (code == 2)
		ft_printf("MLX error\n");
	exit(EXIT_FAILURE);
}

static int	check_digits(char *str)
{
	int		i;
	bool	dot;

	i = 0;
	dot = false;
	if ((str[0] == '-' && str[1] == '\0') || str[0] == '+')
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !dot)
		{
			if (str[i++] == '.')
				dot = true;
			else
				return (0);
		}
		if (!ft_isdigit(str[i]) && dot)
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(char *s)
{
	double	a = 0.0;
	int		e = 0;
	int		c;
	int		sign;
	int		i;

	while ((c = *s++) != '\0' && ft_isdigit(c))
		a = a * 10.0 + (c - '0');
	if (c == '.')
	{
		while ((c = *s++) != '\0' && ft_isdigit(c))
		{
		a = a * 10.0 + (c - '0');
		e = e - 1;
		}
	}
	if (c == 'e' || c == 'E')
	{
		sign = 1;
		i = 0;
		c = *s++;
		if (c == '+')
			c = *s++;
		else if (c == '-')
		{
			c = *s++;
			sign = -1;
		}
		while (ft_isdigit(c))
		{
			i = i * 10 + (c - '0');
			c = *s++;
		}
		e += i * sign;
	}
	while (e-- > 0)
		a *= 10.0;
	while (e++ < 0)
		a *= 0.1;
	return (a);
}

int	check_julia(char *realstr, char *imagstr, t_julia *julia)
{
	ft_printf("Checking...\n");
	if (!check_digits(realstr) && !check_digits(imagstr))
		return (EXIT_FAILURE);
	
	julia->real = ft_atof(realstr);
	julia->imag = ft_atof(imagstr);
	printf("THE VALUES\n REAL:%f\n IMAG:%f\n", julia->real, julia->imag);
	if (julia->real < -0.1)
	{
		ft_printf("fsult..\n");
	}
	if (julia->imag < -0.1)
		ft_printf("fsult..\n");
	return (0);
}

int	check_input(int ac, char **av, t_julia *julia)
{
	if (ac < 2 || ac > 5)
		return (0);
	if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2
		&& ft_strlen(av[1]) == 10)
		return (1);
	if (!ft_strncmp(av[1], "julia", 5) && ac == 4 && ft_strlen(av[1]) == 5)
	{
		if (!check_julia(av[2], av[3], julia))
			return (2);
	}
	return (0);
}
