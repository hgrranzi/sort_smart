/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int			is_in_sequence(t_sorted *sorted, int num)
{
	int		i;

	i = 0;
	while (i < sorted->size)
	{
		if (sorted->sequence[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void		check_push(t_info *info, t_sorted *sorted)
{
	int		*len;
	int		new_sequence_size;

	if (info->b->status)
	{
		len = malloc(info->a->status * sizeof(int)); // needs to be freed somehow
		if (!len)
			display_error();
		push_top(info->a, info->b);
		new_sequence_size = check_sequence(info->a->data, len, info->a->status);
		if (new_sequence_size > sorted->size)
		{
			push(info->cmd, PA);
			free(sorted->sequence);
			sorted->size = new_sequence_size;
			sorted->sequence = make_sequence(len, info->a->data, info->a->status, index_len_max(len, info->a->status));
		}
		else
			push_top(info->b, info->a);
	}
}

void		check_swaps(t_info *info, t_sorted *sorted)
{
	int		*len;
	int		new_sequence_size;

	len = malloc(info->a->status * sizeof(int)); // needs to be freed somehow
	if (!len)
		display_error();
	swap_top(info->a);
	new_sequence_size = check_sequence(info->a->data, len, info->a->status); // расширит ли свап последовательность
	if (new_sequence_size > sorted->size)
	{
		if ((info->b->status > 1) && (info->b->data[info->b->status - 1] < info->b->data[info->b->status - 2])) // probably no need
		{
			swap_top(info->b);
			push(info->cmd, SS);
		}
		else
			push(info->cmd, SA);
		free(sorted->sequence);
		sorted->size = new_sequence_size;
		sorted->sequence = make_sequence(len, info->a->data, info->a->status, index_len_max(len, info->a->status));
	}
	else if (!is_in_sequence(sorted, info->a->data[info->a->status - 1]) && (info->b->status > 1 && info->b->data[info->b->status - 1] < info->b->data[info->b->status - 2])
	&& (info->a->status > 1 && info->a->data[info->a->status - 1] < info->a->data[info->a->status - 2])) // probably no need
	{
		swap_top(info->b);
		push(info->cmd, SS);
	}
	else
		swap_top(info->a);
}

void		move_unsorted(t_info *info, t_sorted *sorted)
{
	while (info->a->status > sorted->size)
	{
		check_push(info, sorted);
		check_swaps(info, sorted); // проверить нужно ли свапнуть а и б
		if (!is_in_sequence(sorted, info->a->data[info->a->status - 1]))
		{
			push_top(info->b, info->a);
			push(info->cmd, PB);
			print_commands(info->cmd, info->commands);
		}
		rotate_stack(info->a);
		push(info->cmd, RA);
	}
	print_commands(info->cmd, info->commands);
}

void		sort_clever(t_info *info)
{
	t_sorted	*sorted;

	index_stack(info->a); // given an index to each element of the stack
	sorted = best_sequence(info->a); // находим наибольшую восходящую последовательность
	move_unsorted(info, sorted);
	/*
	int			i = 0;
	while (i < sorted->size)
	{
		printf("%d ", sorted->sequence[i]);
		i++;
	}
	*/
	// перекидываем в б все кроме последовательности
		// стоит ли выполнить двойную команду
		// проверить не расширилась ли последовательность
	// перекидываем обратно в а
	// находим наибольшую убывающую последовательность
		// для каждого числа в b считаем количество шагов до нужной позиции в а
		// выполняем шаги для того, у кого их меньше
	//sort_stupid(info);
	return ;
}

int			main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	t_stack	cmd;
	char	**commands = NULL;

	info.a = &a; // need to recode the init_stack and creat_stack f afin de faire присваивание
	info.b = &b;
	info.cmd = &cmd;
	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		if (!is_sorted(&a))
		{
			cmd.data = init_stack(&cmd, 20 * argc); // that should realloc when necessary or be cleaned
			info.commands = init_commands(commands, CMD_NUMBER);
			if (!cmd.data || !info.commands)
				display_error();
			sort_clever(&info);
		}
		//print_stack(info.a);
	}
	free(a.data); // сократить код
	free(b.data);
	free(cmd.data);
	return (0);
}
