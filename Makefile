NAME = fractol

SRC = main.c make_pixels.c screen_mod.c fractals.c hooks.c ft_memcmp.c ft_atoi.c icount.c keychecks.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx
	gcc $(OBJ) -lmlx -Lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc -c -o $@ $< -I mlx $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	make clean -C mlx
	rm -f fractol

re: fclean all

bonus: all