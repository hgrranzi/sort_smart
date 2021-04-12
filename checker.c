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

void		checker(t_stack *a, t_stack *b)
{
	return ;
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
