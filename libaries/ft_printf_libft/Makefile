NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRC		= ft_printf.c ft_printf_src.c ft_print_int.c ft_putptr.c get_next_line.c get_next_line_utils.c
OBJ		= $(SRC:.c=.o)
CC		= @cc

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@ar rcs $(NAME) $(OBJ)
			@echo // ft_printf compiled! //

clean:
			@$(RM) $(OBJ)
			@make clean -C libft
			@echo // objekt files removed //

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) libft/libft.a
			@echo // all files removed //

re:			fclean all
			@echo // Clenad and rebuild everything! //

.PHONY:		all clean fclean re