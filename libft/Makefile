# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 18:36:32 by mlazzare          #+#    #+#              #
#    Updated: 2021/06/08 07:47:02 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = ./

SRC	=	ft_strlen.c				\
		ft_numlen.c				\
		ft_strcmp.c			\
		ft_atoi.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isspace.c			\
		ft_strdup.c				\
		ft_substr.c				\
		ft_strchr.c			\
		get_next_line.c				\
		get_next_line_utils.c		\

OBJS = $(SRC:%.c=%.o)

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): 
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRC)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
