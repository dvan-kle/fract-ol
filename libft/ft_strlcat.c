/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:47:26 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:25:17 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = ft_strlen((const char *)dest);
	j = ft_strlen(src);
	result = i + j;
	if (i >= size)
		return (j + size);
	j = 0;
	while (i < size - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dest[i] = '\0';
	return (result);
}
