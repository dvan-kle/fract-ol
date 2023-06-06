/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:44:10 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/18 22:24:14 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	while (*str)
	{
		write (fd, str, 1);
		str++;
	}
	write (fd, "\n", 1);
}
