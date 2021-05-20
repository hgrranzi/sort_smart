NAME_ONE = checker

NAME_TWO = sort_smart

COMPILE = gcc -c

LINK = gcc -Wall -Wextra -Werror

MLX = -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

SRCS_ONE = checker.c checker_cmd.c utils.c stack.c visual.c\
	find_numbers.c get_next_line.c get_next_line_utils.c

SRCS_TWO = sort_smart.c index_stack.c best_sequence.c move_unsorted.c moves.c rotate_it.c move_bestone.c \
	commands.c utils.c find_numbers.c checker_cmd.c stack.c get_next_line.c get_next_line_utils.c

OBJS_ONE =	$(SRCS_ONE:.c=.o)

OBJS_TWO =	$(SRCS_TWO:.c=.o)

all: $(NAME_ONE) $(NAME_TWO)

$(NAME_ONE): get_next_line.h stack.h utils.h checker.h $(OBJS_ONE)
	cd mlx && make
	$(LINK) $(MLX) $(OBJS_ONE) mlx/libmlx.a -o $(NAME_ONE)

$(NAME_TWO): get_next_line.h stack.h utils.h sort_smart.h $(SRCS_TWO)
	$(LINK) $(SRCS_TWO) -o $(NAME_TWO)

%.o: %.c get_next_line.h stack.h utils.h checker.h sort_smart.h
	$(COMPILE) $< -o $@

check: $(NAME_ONE)

sort: $(NAME_TWO)

clean:
	rm -f $(OBJS_ONE) $(OBJS_TWO)

fclean: clean
	rm -f $(NAME_ONE) $(NAME_TWO)
	cd mlx && make clean

re: fclean all
