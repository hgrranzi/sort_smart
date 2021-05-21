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
	info->flag = 1;
}

void	sort_more(t_info *info)
{
	while (info->a->status > 3)
	{
		push_top(info->b, info->a);
		push(info->cmd, PB);
	}
	sort_few(info);
	info->flag = 1;
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

void	copy_stack(t_stack *dst, t_stack *src)
{
	dst->data = copy_stack_data(src);
	if (!dst->data)
		display_error();
	dst->size = src->status;
	dst->status = src->status;
}

void	check_sort(t_info *info, int stack_size, t_stack *cmd_min, t_stack *a_copy)
{
	if (!info->a->data)
		copy_stack(info->a, a_copy);
	sort_smart(info, stack_size);
	destroy_stack(info->a);
	if (info->cmd->status < cmd_min->status)
	{
		destroy_stack(cmd_min);
		copy_stack(cmd_min, info->cmd);
	}
	destroy_stack(info->cmd);
	info->cmd->data = init_stack(info->cmd, info->cmd->status);
	if (!info->cmd->data)
		display_error();
}

void	sort_stack(t_info *info, int stack_size)
{
	t_stack	cmd_min;
	t_stack	a_copy;

	if (stack_size <= 10)
	{
		sort_smart(info, stack_size);
		print_commands(info->cmd, info->commands);
	}
	else
	{
		copy_stack(&a_copy, info->a);
		cmd_min.status = INT_MAX;
		cmd_min.data = NULL;
		while (info->flag)
		{
			check_sort(info, stack_size, &cmd_min, &a_copy);
			info->flag--;
		}
		print_commands(&cmd_min, info->commands);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	t_stack	cmd;
	char	**commands;

	info.a = &a;
	info.b = &b;
	info.cmd = &cmd;
	commands = NULL;
	info.flag = (argc - 1) / DIVISER + 1;
	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		if (!is_sorted(&a))
		{
			info.commands = init_commands(commands, CMD_NUMBER);
			cmd.data = init_stack(&cmd, argc); // need to choose the right size
			if (!cmd.data || !info.commands)
				display_error();
			sort_stack(&info, argc);
		}
	}
	return (0);
}
