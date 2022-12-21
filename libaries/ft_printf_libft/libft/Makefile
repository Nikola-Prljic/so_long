# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:59:02 by nprljic           #+#    #+#              #
#    Updated: 2022/12/09 13:33:17 by nprljic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCES = ft_atoi.c ft_bzero.c ft_tolower.c ft_toupper.c \
      ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
      ft_strlen.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_calloc.c ft_strdup.c \
	  ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_BOUNUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c

MY_BOUNUS_OBJS = $(MY_BOUNUS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

CC = @cc

RM = rm -f

.PHONY: all
all: ${NAME}

$(NAME): $(MY_OBJECTS)
	@ar rcs $(NAME) $(MY_OBJECTS)
	@echo // objekt files created //
	@echo // libft.a created //

.PHONY: clean
clean:
	@$(RM) $(MY_OBJECTS) $(MY_BOUNUS_OBJS)
	@echo // objekt files removed //

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo // all files removed //

.PHONY: re
re: fclean $(NAME)

.PHONY: bonus
bonus: $(MY_OBJECTS) $(MY_BOUNUS_OBJS)
	@ar rcs $(NAME) $(MY_OBJECTS) $(MY_BOUNUS_OBJS)
	@echo // Bounus created //