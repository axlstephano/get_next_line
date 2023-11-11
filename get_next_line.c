/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:23:09 by axcastil          #+#    #+#             */
/*   Updated: 2023/11/11 21:07:28 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char	*buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while(buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	i ++;
	next = malloc(((ft_strlen(buffer)) - i) + 1 * sizeof(char));
	if (!next)
		return(NULL);
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	//printf("%s", next);
	return (next);
}

char	*liner(char	*buffer)
{
	char	*new_line;
	int		len;

	len = 0;
	while(buffer[len] != '\n')
		len ++;
	len ++;
	new_line = ft_substr(buffer, 0, len);
	return(new_line);
}

char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = ft_strjoin(result, buffer);
	free(result);
	return (line);
}

char	*reader(int fd,char *result)
{
	ssize_t	byte_read;
	char	*buffer;

	if (!result)
	{
		result = malloc(1 * sizeof(char));
		result[0] = '\0';
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while(byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if  (byte_read == -1)
			return (NULL);
		buffer[byte_read] = '\0';
		result = joinandfree(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char	*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return(NULL);
	result = reader(fd, result);
	if (!result)
		return (NULL);
	new_line = liner(result);
	result = next_line(result);
	return (new_line);
}

//int main()
//{
//    int fd;
//    char *result;
//    fd = open("text.txt", O_RDONLY);
//    if (fd == -1)
//        return (0);
//    result = get_next_line(fd);
//    while (result != NULL)
//    {
//        printf("%s",result);
//        free(result);
//        result = get_next_line(fd);
//    }
//    close(fd);
//    return(0);
//}
