/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:45:05 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:25:21 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	if (size > ft_strlen(src))
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < (size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
