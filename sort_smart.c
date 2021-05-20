/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

void	sort_few(t_info *info)
{
	if (info->a->status == 2
		|| ((info->a->data[2] > info->a->data[1])
			&& (info->a->data[2] < info->a->data[0]))
		|| ((info->a->data[1] > info->a->data[0])
			&& (info->a->data[1] < info->a->data[2]))
		|| ((info->a->data[0] > info->a->data[2])
			&& (info->a->data[0] < info->a->data[1])))
	{
		swap_top(info->a);
		push(info->cmd, SA);
	}
}

void	sort_more(t_info *info)
{
	while (info->a->status > 3)
	{
		push_top(info->b, info->a);
		push(info->cmd, PB);
	}
	sort_few(info);
}

void	sort_clever(t_info *info)
{
	t_stack	*sorted;

	sorted = best_sequence(info->a); // находим наибольшую восходящую последовательность
	move_unsorted(info, sorted);
	// probably from here we dont need our sequence anymore
	return ;
}

void	sort_smart(t_info *info, int stack_size)
{
	index_stack(info->a); // given an index to each element of the stack
	if (stack_size <= 4)
		sort_few(info);
	else if (stack_size <= 10)
		sort_more(info);
	else
		sort_clever(info);
	move_bestone(info); // перекидываем обратно в а
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	t_stack	cmd;
	t_stack	cmd_tmp;
	char	**commands;

	info.a = &a;
	info.b = &b;
	info.cmd = &cmd;
	commands = NULL;
	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		if (!is_sorted(&a))
		{
			info.flag = 0;
			cmd.data = init_stack(&cmd, argc);
			info.commands = init_commands(commands, CMD_NUMBER);
			if (!cmd.data || !info.commands)
				display_error();
			sort_smart(&info, argc);
			info.flag = 1;
			info.cmd = &cmd_tmp;
			create_stacks(argv, argc - 1, &a, &b);
			cmd_tmp.data = init_stack(&cmd_tmp, argc);
			if (!cmd_tmp.data)
				display_error();
			sort_smart(&info, argc);
		}
	}
	if (cmd.status < cmd_tmp.status)
		print_commands(&cmd, info.commands); // that can be more optimized
	else
		print_commands(info.cmd, info.commands);
	free(a.data); // сократить код
	free(b.data);
	free(cmd.data);
	return (0);
}
