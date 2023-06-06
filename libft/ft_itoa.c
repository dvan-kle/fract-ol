/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:44:14 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:22:57 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n);
static char	*min_int(char *ptr);
static char	*number(char *ptr, int n, int len);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = ft_len(n);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (n == -2147483648)
		return (min_int(ptr));
	ptr[len--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	else
	ptr = number(ptr, n, len);
	return (ptr);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*min_int(char *ptr)
{
	int		i;
	char	*str;

	str = "-2147483648";
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*number(char *ptr, int n, int len)
{
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		ptr[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ptr);
}
