/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:14 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/16 14:03:05 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	a = gnl_strlen(s1);
	b = gnl_strlen(s2);
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

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = NULL;
	if (!*s || gnl_strlen(s) <= start)
	{
		new_str = malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	if (gnl_strlen(s + start) <= len)
		len = gnl_strlen(s + start);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < gnl_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

void	*gnl_calloc(size_t count, size_t size)
{
	char	*string;
	size_t	i;

	string = (char *)malloc(count * size);
	if (!string)
		return (NULL);
	i = 0;
	while (i < count * size)
		string[i++] = 0;
	return (string);
}
