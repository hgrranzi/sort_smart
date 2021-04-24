/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int			positive(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int			max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int			moves(t_stack *stack, int index)
{
	int		rot;
	int		reverse_rot;

	rot = stack->status - 1 - index;
	reverse_rot = index + 1;
	if (reverse_rot < rot)
		return (-reverse_rot);
	return (rot);
}

int			count_moves(int b_moves, int a_moves)
{
	int		moves;

	if ((b_moves < 0 && a_moves < 0) || (b_moves > 0 && a_moves > 0))
		moves = max(positive(b_moves), positive(a_moves));
	else
		moves = positive(b_moves) + positive(a_moves);
	return (moves);
}

int			right_place(t_stack *stack, int num)
{
	int		i;
	int		index_min;
	int		min;
	int		max;

	index_min = find_min(stack);
	min = stack->data[index_min]; // needs to be recoded as find_max
	max = find_max(stack);
	if (num > max || num < min)
		return (index_min);
	i = stack->status - 1;
	if (num > stack->data[i] && num < stack->data[0])
		return (i);
	while (i >= 0)
	{
		if (num > stack->data[i + 1] && num < stack->data[i])
			break ;
		i--;
	}
	return (i);
}

void		move_bestone(t_info *info)
{
	int		i;
	//int		min_moves;
	//int		current_best;

	i = info->b->status - 1;
	while (i >= 0)
	{
		count_moves(moves(info->b, i), moves((info->a), right_place(info->a, info->b->data[i])));
		i--;
	}
}

void		sort_clever(t_info *info)
{
	t_sorted	*sorted;

	index_stack(info->a); // given an index to each element of the stack
	sorted = best_sequence(info->a); // находим наибольшую восходящую последовательность
	move_unsorted(info, sorted);

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
	move_bestone(info); // перекидываем обратно в а
	// находим наибольшую убывающую последовательность ?
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
