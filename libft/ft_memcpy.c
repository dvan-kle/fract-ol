/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:18:58 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:23:23 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *sc, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	dest = (char *)dst;
	src = (char *)sc;
	i = 0;
	if (dst == 0 && sc == 0)
		return (0);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dst);
}
