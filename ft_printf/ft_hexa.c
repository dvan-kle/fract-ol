/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielvankleef <danielvankleef@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:49:02 by dvan-kle          #+#    #+#             */
/*   Updated: 2022/11/09 22:32:34 by danielvankl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(size_t nb, char format)
{
	if (nb > 15)
	{
		puthexa(nb / 16, format);
		puthexa(nb % 16, format);
	}
	else
	{
		if (nb < 10)
		{
			ft_putchar(nb + '0');
		}	
		else
		{
			if (format == 'X')
				ft_putchar(nb - 10 + 'A');
			if (format == 'x' || format == 'p')
				ft_putchar(nb - 10 + 'a');
		}
	}
}

static int	h_len(size_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_hexa(size_t nb, char format)
{
	if ((format == 'X') || (format == 'x'))
	{
		if (nb == 0)
			return (ft_putchar('0'));
		puthexa(nb, format);
		return (h_len(nb));
	}
	else
	{
		ft_putstr("0x");
		if (nb == 0)
			return (ft_putchar('0') + 2);
		puthexa(nb, format);
		return (h_len(nb) + 2);
	}
}
