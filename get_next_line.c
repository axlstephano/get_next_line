/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:40:53 by axcastil          #+#    #+#             */
/*   Updated: 2023/11/08 20:36:56 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *result)
{
	char	*buffer;
	size_t	byte_read;

	if(!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	byte_read = 1;
	while(byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE + 1);
		if (byte_read == -1)
			return (NULL);
		buffer[byte_read] = '\0';
		result = joinline(result, buffer);
		if (ft_strchr(buffer, '\n'));
			break;
	}
	free(buffer);
		
}

get_next_line(int fd)
{
	static char	*result;
	
	//error handling
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = reader(fd, result);
	
}

//main
int main(void)
{
	int		fd;
	char	*parson;

	fd = open("text.txt", O_RDONLY);
	//parson = get_next_line(fd);
	printf("%d", yo(fd));
	return (0);
}
