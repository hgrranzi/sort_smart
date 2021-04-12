/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void		display_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

int			is_duplicate(int nbr, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->status)
	{
		if (stack->data[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int			is_sorted(t_stack *stack)
{
	int		i;

	i = stack->status - 1;
	while (i > 0)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void		exec_cmd(char *line, t_stack *a, t_stack *b)
{
	if (strcmp(line, "sa") == 0)
		swap_top(a);
	else if (strcmp(line, "sb") == 0)
		swap_top(b);
	else if (strcmp(line, "ss") == 0)
	{
		swap_top(a);
		swap_top(b);
	}
	else if (strcmp(line, "pa") == 0)
		push_top(a, b);
	else if (strcmp(line, "pb") == 0)
		push_top(b, a);
	else if (strcmp(line, "ra") == 0)
		rotate_stack(a);
	else if (strcmp(line, "rb") == 0)
		rotate_stack(b);
	else if (strcmp(line, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (strcmp(line, "rra") == 0)
		reverse_rotate_stack(a);
	else if (strcmp(line, "rrb") == 0)
		reverse_rotate_stack(b);
	else if (strcmp(line, "rrr") == 0)
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else
		display_error();
}

void		swap_top(t_stack *stack)
{
	int		tmp;

	if (stack->status > 1)
	{
		tmp = stack->data[stack->status - 1];
		stack->data[stack->status - 1] = stack->data[stack->status - 2];
		stack->data[stack->status - 2] = tmp;
	}
}

void		push_top(t_stack *a, t_stack *b)
{
	if (b->status > 0)
		push(a, (pop(b)));
}

void		rotate_stack(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->status > 1)
	{
		i = stack->status - 1;
		tmp = stack->data[i];
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[i] = tmp;
	}
}

void		reverse_rotate_stack(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->status > 1)
	{
		i = 0;
		tmp = stack->data[i];
		while (i < stack->status - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[i] = tmp;
	}
}

void		checker(t_stack *a, t_stack *b)
{
	int		readed;
	char	*line;

	while (get_next_line(0, &line))
		exec_cmd(line, a, b);
	if (is_empty(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int			main(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_stack	a;
	t_stack	b;

	i = argc - 1;
	if (argc > 1)
	{
		if (!(init_stack(&a, argc - 1)) || (!init_stack(&b, argc - 1)))
			display_error();
		while (i > 0)
		{
			nbr = aka_atoi(argv[i]);
			if (is_duplicate(nbr, &a))
				display_error();
			push(&a, nbr);
			i--;
		}
		checker(&a, &b);
		print_stack(&a);
	}
	return (0);
}
