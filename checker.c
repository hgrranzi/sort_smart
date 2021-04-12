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
	return (0);
}

void		exec_operation(t_stack *a, t_stack *b, int name)
{
	return ;
}

int			check_operation(char *line)
{
	return (0);
}

void		checker(t_stack *a, t_stack *b)
{
	int		readed;
	char	*line;
	int		name;

	while (get_next_line(0, &line))
	{
		name = check_operation(line);
		exec_operation(a, b, name);
	}
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

	i = 1;
	if (argc > 1)
	{
		if (!(init_stack(&a, argc - 1)) || (!init_stack(&b, argc - 1)))
			display_error();
		while (i < argc)
		{
			nbr = aka_atoi(argv[i]);
			if (is_duplicate(nbr, &a))
				display_error();
			push(&a, nbr);
			i++;
		}
		checker(&a, &b);
		print_stack(&a);
	}
	return (0);
}
