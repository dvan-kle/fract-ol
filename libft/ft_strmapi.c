/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:56:42 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/13 15:07:43 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(str);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = f(i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
