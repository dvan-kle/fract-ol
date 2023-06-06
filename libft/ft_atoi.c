/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:34:48 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/05/20 15:57:09 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *str)
{
	int			i;
	int			minplus;
	long long	result;

	i = 0;
	minplus = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minplus = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * minplus);
}
