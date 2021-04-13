/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

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
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		checker(&a, &b);
		print_stack(&a);
		print_stack(&b);
	}
	return (0);
}
