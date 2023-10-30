/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:31:08 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/30 11:16:18 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd)
{
	char	*buffer;
	size_t	rdbyte;

	buffer = malloc(BUFFERSIZE + 1);
	if (!buffer)
		return (NULL);
	rdbyte = read(fd, buffer, BUFFERSIZE);
	if (rdbyte == -1)
		return (NULL);
	buffer[BUFFERSIZE] = '\0';
	return (buffer);
}

static char	*finaltext(char *string)
{
	size_t	f;

	f = (size_t)(ft_strchr(string, '\n')) - (size_t)string;
	return (ft_substr(string, 0, f + 1));
}

char	*get_next_line(int fd)
{
	char	*string;
	char	*line;

	if (fd < 0 || BUFFERSIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	while (!ft_strchr(string, '\n'))
	{
		string = reader(fd);
		if (ft_strchr(string, '\n'))
			string = finaltext(string);
		line = ft_strjoin(line, string);
		free (string);
	}
	return (line);
}

void	leaks(void) {
	system("leaks -q test");
}

int main()
{
	int	source = open("words.txt", O_RDONLY);
	int i = 3;
	while(i--)
	{
		char	*line = get_next_line(source);
		printf ("%s", line);
	}
	//atexit(leaks);
	return 0;
}
