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
	return ;
}

int			main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 1;
	if (argc > 1)
	{
		if (!(init_stack(&a, argc - 1)) || (!init_stack(&b, argc - 1)))
			display_error();
		while (i < argc)
		{
			push(&a, aka_atoi(argv[i]));
			i++;
		}
		checker(&a, &b);
		print_stack(&a);
	}
	return (0);
}
