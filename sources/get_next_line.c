/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:23:09 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/16 14:01:26 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = gnl_strjoin(result, buffer);
	free(result);
	return (line);
}

char	*read_file(int fd, char *result)
{
	int		byte_read;
	char	*buffer;

	if (!result)
		result = gnl_calloc(1, sizeof(char));
	buffer = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
	{
		free(result);
		return (NULL);
	}
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		result = joinandfree(result, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*liner(char **result)
{
	char	*new_line;
	int		len;

	len = 0;
	if ((*result)[len] == 0)
		return (NULL);
	while ((*result)[len] != '\n' && (*result)[len] != '\0')
		len++;
	len++;
	new_line = gnl_substr(*result, 0, len);
	if (new_line == NULL)
	{
		free(*result);
		*result = NULL;
	}
	return (new_line);
}

char	*next_line(char *buffer, int *err)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	next = gnl_calloc((gnl_strlen(buffer) - i + 1), sizeof(char));
	if (!next)
	{
		*err = 1;
		return (free(buffer), NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*new_line;
	int			err;

	err = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (result)
		{
			free(result);
			result = NULL;
		}
		return (NULL);
	}
	result = read_file(fd, result);
	if (!result)
		return (NULL);
	new_line = liner(&result);
	result = next_line(result, &err);
	if (err == 1)
		return (free(new_line), NULL);
	return (new_line);
}