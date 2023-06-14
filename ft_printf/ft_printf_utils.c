/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: danielvankleef <danielvankleef@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:35:30 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/11 15:23:42 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

static int	ft_len(ssize_t nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_itoa_printf(ssize_t nb, int len)
{
	char	*ptr;

	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (-1);
	ptr[len--] = '\0';
	if (nb == 0)
		ptr[0] = '0';
	else
	{
		if (nb < 0)
		{
			ptr[0] = '-';
			nb = -nb;
		}
		while (nb != 0)
		{
			ptr[len] = (nb % 10) + '0';
			nb = nb / 10;
			len--;
		}
	}
	ft_putstr(ptr);
	return (free(ptr), 0);
}

int	ft_convert(ssize_t nb)
{
	int		len;

	len = ft_len(nb);
	if (ft_itoa_printf(nb, len) == -1)
		return (-1);
	return (len);
}
