/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:29:25 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:23:44 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) b;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
