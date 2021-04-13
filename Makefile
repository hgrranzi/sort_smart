NAME = checker

COMPILE = gcc -c

LINK = gcc -Wall -Wextra -Werror

SRCS = checker.c checker_cmd.c checker_utils.c stack.c \
	get_next_line.c get_next_line_utils.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): get_next_line.h stack.h checker.h $(OBJS)
	$(LINK) $(OBJS) -o $(NAME)

%.o: %.c get_next_line.h stack.h checker.h
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
