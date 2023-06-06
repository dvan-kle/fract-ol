/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:03:46 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:26:22 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t		start;
	size_t		end;

	start = 0;
	end = ft_strlen(str);
	while (ft_strchr(set, str[start]) != 0 && start < ft_strlen(str))
		start++;
	while (ft_strchr(set, str[end]) != 0 && start < end)
		end--;
	return (ft_substr(str, start, (end - start + 1)));
}
