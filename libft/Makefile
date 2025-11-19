# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 13:04:07 by raisufaj          #+#    #+#              #
#    Updated: 2024/11/21 11:51:37 by raisufaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

ALLSRCS = $(SOURCES) $(BONUS)

OBJECTS = $(SOURCES:.c=.o)

ALLOBJS = $(ALLSRCS:.c=.o)

%.o : %.c
		$(CC) -c $(CFLAGS) $< -o $@ -I ./

.PHONY : all clean fclean re bonus

$(NAME) : $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

all : $(NAME)

clean :
		$(RM) $(ALLOBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

bonus : $(ALLOBJS)
		ar rc $(NAME) $(ALLOBJS)

