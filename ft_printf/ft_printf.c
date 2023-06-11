/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielvankleef <danielvankleef@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:21:39 by dvan-kle          #+#    #+#             */
/*   Updated: 2022/11/10 13:56:19 by danielvankl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	find_format(char c, va_list list)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(list, int));
	else if (c == 's')
		length += ft_putstr(va_arg(list, char *));
	else if (c == 'p')
		length += ft_hexa(va_arg(list, unsigned long), c);
	else if (c == 'd' || c == 'i')
		length += ft_convert(va_arg(list, int));
	else if (c == 'u')
		length += ft_convert(va_arg(list, unsigned int));
	else if (c == 'x')
		length += ft_hexa(va_arg(list, unsigned int), c);
	else if (c == 'X')
		length += ft_hexa(va_arg(list, unsigned int), c);
	else if (c == '%')
		length += ft_putchar('%');
	else if (c == '\0')
		return (0);
	else
		length += ft_putchar(c);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	list;

	va_start(list, str);
	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += find_format(str[i + 1], list);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		if (str[i] != '\0')
			i++;
	}
	return (va_end(list), length);
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
