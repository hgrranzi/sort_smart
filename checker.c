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
		print_stack(&b);
	}
	return (0);
}
