# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 19:54:11 by luigi_streb       #+#    #+#              #
#    Updated: 2024/08/06 16:56:36 by luigi_streb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = habitsapp

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c habit_tracker.c
INCLUDE = habit_tracker.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
