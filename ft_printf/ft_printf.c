/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danielvankleef <danielvankleef@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 13:21:39 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/14 15:58:32 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	find_format(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_hexa(va_arg(list, unsigned long), c));
	else if (c == 'd' || c == 'i')
		return (ft_convert(va_arg(list, int)));
	else if (c == 'u')
		return (ft_convert(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (ft_hexa(va_arg(list, unsigned int), c));
	else if (c == 'X')
		return (ft_hexa(va_arg(list, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == '\0')
		return (0);
	else
		return (ft_putchar(c));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	int		tmp;
	va_list	list;

	va_start(list, str);
	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			tmp = find_format(str[i + 1], list);
			if (tmp == -1)
				return (-1);
			length += tmp;
			i++;
		}
		else
			length += ft_putchar(str[i]);
		if (str[i] != '\0')
			i++;
	}
	va_end(list);
	return (length);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
