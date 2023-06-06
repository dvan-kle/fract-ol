/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:00:44 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/01 01:46:04 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

int	find_len(char const *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**ptr;
	int		i;
	int		j;

	ptr = (char **)malloc((word_count(str, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count(str, c))
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			ptr[j] = ft_substr(str, i, find_len(str, i, c));
			if (!ptr[j])
				return (ft_free(ptr));
			i += find_len(str, i, c);
			j++;
		}
		i++;
	}
	ptr[word_count(str, c)] = 0;
	return (ptr);
}
