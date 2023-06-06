/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:01:56 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:24:43 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (ptr[i] != (char)c)
	{
		if (ptr[i] == 0)
			return (NULL);
		i++;
	}
	return (&ptr[i]);
}
