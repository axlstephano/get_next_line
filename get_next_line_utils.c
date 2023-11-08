/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:14 by axcastil          #+#    #+#             */
/*   Updated: 2023/11/08 20:44:13 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	str = malloc(a + b + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (a--)
	{
		str[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		str[a++] = s2[i++];
	str[a] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*string;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	string = malloc(count * size);
	if (!string)
		return (NULL);
	ft_bzero(string, count * size);
	return (string);
}