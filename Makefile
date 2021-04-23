NAME = checker

NAME_TWO = sort_smart

COMPILE = gcc -c

LINK = gcc -Wall -Wextra -Werror

MLX = -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

SRCS = checker.c checker_cmd.c utils.c stack.c visual.c\
	get_next_line.c get_next_line_utils.c

SRCS_TWO = sort_smart.c index_stack.c best_sequence.c sort_stupid.c utils.c \
	checker_cmd.c stack.c get_next_line.c get_next_line_utils.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): get_next_line.h stack.h utils.h checker.h $(OBJS)
	cd mlx && make
	$(LINK) $(MLX) $(OBJS) mlx/libmlx.a -o $(NAME)

$(NAME_TWO): get_next_line.h stack.h utils.h sort_smart.h $(SRCS_TWO)
	$(LINK) $(SRCS_TWO) -o $(NAME_TWO)

%.o: %.c get_next_line.h stack.h utils.h checker.h sort_smart.h
	$(COMPILE) $< -o $@

sort: $(NAME_TWO)

clean:
	rm -f $(OBJS) $(OBJS_TWO)

fclean: clean
	rm -f $(NAME) $(NAME_TWO)
	cd mlx && make clean

re: fclean all
