/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int			right_place(t_stack *stack, int num)
{
	int		i;
	int		index_min;
	int		min;
	int		max;

	index_min = find_min(stack);
	min = stack->data[index_min];
	max = find_max(stack);
	if (num > max || num < min)
		return (index_min);
	i = stack->status - 1;
	if (num < stack->data[i] && num > stack->data[0])
		return (i);
	i = stack->status - 2;
	while (i >= 0)
	{
		if (num > stack->data[i + 1] && num < stack->data[i])
			break ;
		i--;
	}
	return (i);
}

void		find_bestone(t_stack *a, t_stack *b, t_moves *bestone) // для каждого числа в b считаем количество шагов до нужной позиции в а
{
	int		current_moves;
	int		min_moves;
	t_moves	index;
	t_moves	moves;

	index.b = b->status - 1;
	min_moves = INT_MAX;
	while (index.b >= 0)
	{
		index.a = right_place(a, b->data[index.b]);
		check_moves(a, b, index, &moves);
		current_moves = count_moves(moves.b, moves.a);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			bestone->a = moves.a;
			bestone->b = moves.b;
		}
		index.b--;
	}
}

void		exec_reverse_rotate(t_info *info, t_moves *bestone)
{
	while (bestone->a < 0 && bestone->b < 0)
	{
		push(info->cmd, RRR);
		reverse_rotate_stack(info->a);
		reverse_rotate_stack(info->b);
		bestone->a++;
		bestone->b++;
	}
	while (bestone->a < 0)
	{
		push(info->cmd, RRA);
		reverse_rotate_stack(info->a);
		bestone->a++;
	}
	while (bestone->b < 0)
	{
		push(info->cmd, RRB);
		reverse_rotate_stack(info->b);
		bestone->b++;
	}
	print_commands(info->cmd, info->commands);
}

void		exec_rotate(t_info *info, t_moves *bestone)
{
	while (bestone->a > 0 && bestone->b > 0)
	{
		push(info->cmd, RR);
		rotate_stack(info->a);
		rotate_stack(info->b);
		bestone->a--;
		bestone->b--;
	}
	while (bestone->a > 0)
	{
		push(info->cmd, RA);
		rotate_stack(info->a);
		bestone->a--;
	}
	while (bestone->b > 0)
	{
		push(info->cmd, RB);
		rotate_stack(info->b);
		bestone->b--;
	}
	print_commands(info->cmd, info->commands);
}

void		move_bestone(t_info *info)
{
	t_moves	bestone;
	int		first_one;
	int		rot;
	int		reverse_rot;

	while (info->b->status)
	{
		find_bestone(info->a, info->b, &bestone);
		exec_rotate(info, &bestone); // выполняем шаги для того, у кого их меньше
		exec_reverse_rotate(info, &bestone);
		push(info->cmd, PA);
		push_top(info->a, info->b);
	}
	print_commands(info->cmd, info->commands);
	first_one = find_min(info->a);
	rot = info->a->status - 1 - first_one;
	reverse_rot = first_one + 1;
	if (rot > reverse_rot)
		bestone.a = -reverse_rot;
	else
		bestone.a = rot;
	exec_rotate(info, &bestone);
	exec_reverse_rotate(info, &bestone);
}

void		sort_clever(t_info *info)
{
	t_sorted	*sorted;
	int			first_one;

	index_stack(info->a); // given an index to each element of the stack
	sorted = best_sequence(info->a); // находим наибольшую восходящую последовательность
	move_unsorted(info, sorted);
	move_bestone(info); // перекидываем обратно в а
	first_one = find_min(info->a);

	//print_stack(info->a);
	//print_stack(info->b);
	/*
	while (i < sorted->size)
	{
		printf("%d ", sorted->sequence[i]);
		i++;
	}
	*/
	// probably from here we dont need our sequence anymore
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
