/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int		main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	t_stack	cmd;

	info.a = &a; // need to recode the init_stack and creat_stuck f afin de faire присваивание
	info.b = &b;
	info.cmd = &cmd;
	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		if (!is_sorted(&a))
		{
			cmd.data = init_stack(&cmd, argc);
			if (!cmd.data)
				display_error();
			sort_stupid(&info);
		}
	}
	free(a.data); // сократить код
	free(b.data);
	free(cmd.data);
	return (0);
}
