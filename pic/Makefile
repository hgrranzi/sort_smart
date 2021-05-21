NAME_ONE = checker

NAME_TWO = sort_smart

COMPILE = clang -Wall -Wextra -Werror

MLX = -Iminilibx-linux -Lminilibx-linux

MLXX = -lmlx -lXext -lX11 ./minilibx-linux/libmlx.a -lm

SRCS_ONE = checker.c checker_cmd.c utils.c stack.c visual.c\
	find_numbers.c get_next_line.c get_next_line_utils.c

SRCS_TWO = draft.c sort_smart.c index_stack.c best_sequence.c move_unsorted.c moves.c rotate_it.c move_bestone.c \
	commands.c utils.c find_numbers.c checker_cmd.c stack.c get_next_line.c get_next_line_utils.c

all: $(NAME_ONE) $(NAME_TWO)

$(NAME_ONE): get_next_line.h stack.h utils.h checker.h $(SRCS_ONE)
	cd minilibx-linux && make
	$(COMPILE) $(MLX) $(SRCS_ONE) $(MLXX) -o $(NAME_ONE)

$(NAME_TWO): get_next_line.h stack.h utils.h sort_smart.h $(SRCS_TWO)
	$(COMPILE) $(MLX) $(SRCS_TWO) $(MLXX) -o $(NAME_TWO)

check: $(NAME_ONE)

sort: $(NAME_TWO)

clean:
	rm -f $(NAME_ONE) $(NAME_TWO)

fclean: clean
	cd minilibx-linux && make clean

re: fclean re
