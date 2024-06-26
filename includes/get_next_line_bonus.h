/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:25:36 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/16 14:11:06 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line_bonus(int fd);
char	*gnlb_strjoin(char const *s1, char const *s2);
size_t	gnlb_strlen(const char *str);
char	*gnlb_strchr(const char *s, int c);
char	*gnlb_substr(const char *s, unsigned int start, size_t len);
void	*gnlb_calloc(size_t count, size_t size);

#endif