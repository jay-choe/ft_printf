# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 23:54:43 by jaehchoi          #+#    #+#              #
#    Updated: 2020/12/26 12:52:35 by jaehchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall
SRCS = ft_atoi.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c \
	   ft_strlen.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	   ft_split.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	   ft_strnstr.c ft_strncmp.c ft_strrchr.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c \
	   ft_calloc.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOBJS = $(BSRCS:.c=.o)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(BOBJS)
	ar -rcs $(NAME) $(BOBJS)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
