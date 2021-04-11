NAME = checker

COMPILE = gcc -c

LINK = gcc -Wall -Wextra -Werror

SRCS = checker.c checker_utils.c stack.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): checker.h $(OBJS)
	$(LINK) $(OBJS) -o $(NAME)

%.o: %.c checker.h
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
