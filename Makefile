NAME	= so_long
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
CC		= cc

SRC		= so_long.c so_long_ultis.c readmatrix.c move.c maptest.c render.c maptest_ultis.c keypress.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@make -C mlx_linux
	@make -C libaries/ft_printf_libft 
	@$(CC) $(CFLAGS) $(OBJ) libaries/ft_printf_libft/libftprintf.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo // done! //

1:
	@./$(NAME) "1.ber"

2:
	@./$(NAME) "2.ber"

3:
	@./$(NAME) "3.ber"

4:
	@./$(NAME) "4.ber"

5:
	@./$(NAME) "5.ber"

clean:
	@make clean -C libaries/ft_printf_libft
	@$(RM) $(OBJ)
	@make clean -C mlx_linux
	@echo // *.o removed //

fclean: clean
	@$(RM) so_long
	@make fclean -C libaries/ft_printf_libft
	@echo // so_long removed //

re: fclean all
