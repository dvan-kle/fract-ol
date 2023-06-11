/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielvankleef <danielvankleef@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:50:45 by dvan-kle          #+#    #+#             */
/*   Updated: 2022/11/10 13:54:15 by danielvankl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int     ft_putchar(int c);
int     ft_putstr(char *str);
int     ft_convert(ssize_t nb);
int     ft_hexa(size_t nb, char format);
size_t  ft_strlen(const char *str);
int     ft_printf(const char *str, ...);

#endif