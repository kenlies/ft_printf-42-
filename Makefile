# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#              #
#    Updated: 2022/11/25 01:19:02 by aotsala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprinft.a
CFLAGS = -c -Wall -Wextra -Werror
CC = cc
INCLDUES = srcs/ft_printf.h srcs/libft.h

SRCS = \
		srcs/ft_printf.c srcs/ft_printf_c.c srcs/ft_printf_d.c \
		srcs/ft_printf_s.c srcs/ft_printf_p.c \
		srcs/ft_printf_u.c srcs/ft_printf_x.c \
		srcs/ft_printf_utils.c srcs/ft_format_utils.c

LIB_SRCS = \
		libft/ft_isdigit.c libft/ft_strlen.c libft/ft_itoa.c \
		libft/ft_ulitoa_hex.c libft/ft_substr.c \
		libft/ft_uitoa.c libft/ft_toupper.c 

SRCS_OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(LIB_SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(SRCS_OBJS) $(LIB_OBJS)

		$(CC) $(CFLAGS) -I $(INCLUDES) $(SRCS) $(LIB_SRCS)
		ar -rcs $(NAME) $(SRCS_OBJS) $(LIB_OBJS)


clean:
		rm -f $(SRCS_OBJS) $(LIB_OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
