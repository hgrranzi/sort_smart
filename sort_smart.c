/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		print_stack(&a);
		print_stack(&b);
	}
	return (0);
}
