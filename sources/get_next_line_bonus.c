/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:20:54 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/16 14:27:25 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

static char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = gnlb_strjoin(result, buffer);
	free(result);
	return (line);
}

static char	*read_file(int fd, char *result)
{
	int		byte_read;
	char	*buffer;

	if (!result)
		result = gnlb_calloc(1, sizeof(char));
	buffer = gnlb_calloc((BUFFER_SIZE + 1), sizeof(char));
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
		if (gnlb_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

static char	*liner(char **buffer)
{
	char	*new_line;
	int		len;

	len = 0;
	if ((*buffer)[len] == 0)
		return (NULL);
	while ((*buffer)[len] != '\n' && (*buffer)[len] != '\0')
		len++;
	len++;
	new_line = gnlb_substr(*buffer, 0, len);
	if (new_line == NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (new_line);
}

static char	*next_line(char *buffer, int *err)
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
	next = gnlb_calloc((gnlb_strlen(buffer) - i + 1), sizeof(char));
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

char	*get_next_line_bonus(int fd)
{
	static char	*result[1024];
	char		*new_line;
	int			err;

	err = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (result[fd])
		{
			free(result[fd]);
			result[fd] = NULL;
		}
		return (NULL);
	}
	result[fd] = read_file(fd, result[fd]);
	if (!result[fd])
		return (NULL);
	new_line = liner(&result[fd]);
	result[fd] = next_line(result[fd], &err);
	if (err == 1)
		return (free(new_line), NULL);
	return (new_line);
}
