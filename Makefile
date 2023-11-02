# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 23:16:42 by axcastil          #+#    #+#              #
#    Updated: 2023/11/02 16:07:07 by axcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	get_next_line.c get_next_line_utils.c

CC 			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
NAME		= 	get_next_line
all:		$(NAME)

$(NAME):	$(SRCS)
			@$(CC) $(SRCS) -o test

cc:
			@./test

clean:		
			@$(RM) test
	
