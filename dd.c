/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:40:53 by axcastil          #+#    #+#             */
/*   Updated: 2023/11/11 19:25:02 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinandfree(char *buffer1, char *buffer2)
{
	char	*new;

	new = ft_strjoin(buffer1, buffer2);
	free(buffer1);
	return(new);
}

char	*next_line(char	*buffer)
{
	
}

char	*liner(char *buffer)
{
	char	*newline;
	size_t	len;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	newline = (char *)ft_calloc((len + 2), sizeof(char));
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		newline[len] = buffer[len];
		len++;
	}
	if (buffer[len] == '\n')
		newline[len] = '\n';
	return (newline);
}

char	*reader(int fd, char *result)
{
	char	*buffer;
	ssize_t	byte_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE + 1);
		if (byte_read == -1)
			return (NULL);
		buffer[byte_read] = '\0';
		result = joinandfree(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*new_line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = reader(fd, result);
	if (!result)
		return (NULL);
	new_line = liner(result);
	result = next_line(result);
	return (new_line);
}

int main(void)
{
	int		fd;
	char	*parson;

	fd = open("text.txt", O_RDONLY);
	parson = get_next_line(fd);
	printf("%s", parson);
	parson = get_next_line(fd);
	printf("%s", parson);
	close(fd);
	return (0);
}
