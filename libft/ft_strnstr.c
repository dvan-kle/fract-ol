/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:51:57 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:25:58 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char *ptr, const char *find, size_t i, size_t j);

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	cp;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	if (find[0] == '\0')
		return (ptr);
	if (len == 1 && ptr[i] == find[0])
		return (&ptr[i]);
	while (ptr[i] && i < len - 1)
	{
		if (ptr[i] == find[0])
		{
			cp = i;
			if (ft_find(ptr, find, i, len) == 1)
				return (&ptr[cp]);
			i = cp;
		}
		i++;
	}
	return (0);
}

static int	ft_find(char *ptr, const char *find, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (ptr[i] == find[j])
	{
		i++;
		j++;
		if (find[j] == '\0' && i <= len)
			return (1);
	}
	return (0);
}
