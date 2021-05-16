/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int	right_place(t_stack *stack, int num)
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

void	find_bestone(t_stack *a, t_stack *b, t_moves *bestone) // для каждого числа в b считаем количество шагов до нужной позиции в а
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

void	exec_reverse_rotate(t_info *info, t_moves *bestone)
{
	while (bestone->a < 0 && bestone->b < 0)
	{
		write(1, "rrr\n", 4);
		reverse_rotate_stack(info->a);
		reverse_rotate_stack(info->b);
		bestone->a++;
		bestone->b++;
	}
	while (bestone->a < 0)
	{
		write(1, "rra\n", 4);
		reverse_rotate_stack(info->a);
		bestone->a++;
	}
	while (bestone->b < 0)
	{
		write(1, "rrb\n", 4);
		reverse_rotate_stack(info->b);
		bestone->b++;
	}
}

void	exec_rotate(t_info *info, t_moves *bestone)
{
	while (bestone->a > 0 && bestone->b > 0)
	{
		write(1, "rr\n", 3);
		rotate_stack(info->a);
		rotate_stack(info->b);
		bestone->a--;
		bestone->b--;
	}
	while (bestone->a > 0)
	{
		write(1, "ra\n", 3);
		rotate_stack(info->a);
		bestone->a--;
	}
	while (bestone->b > 0)
	{
		write(1, "rb\n", 3);
		rotate_stack(info->b);
		bestone->b--;
	}
}

void	move_bestone(t_info *info)
{
	t_moves	bestone;
	int		first_one;
	int		rot;
	int		reverse_rot;

	bestone.a = 0;
	bestone.b = 0;
	while (info->b->status)
	{
		find_bestone(info->a, info->b, &bestone);
		exec_rotate(info, &bestone); // выполняем шаги для того, у кого их меньше
		exec_reverse_rotate(info, &bestone);
		write(1, "pa\n", 3);
		push_top(info->a, info->b);
	}
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

void	sort_clever(t_info *info)
{
	t_sorted	*sorted;

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
	//sort_stupid(info);
	return ;
}

void	sort_few(t_info *info)
{
	if (info->a->status == 2
	|| ((info->a->data[2] > info->a->data[1]) && (info->a->data[2] < info->a->data[0]))
	|| ((info->a->data[1] > info->a->data[0]) && (info->a->data[1] < info->a->data[2]))
	|| ((info->a->data[0] > info->a->data[2]) && (info->a->data[0] < info->a->data[1])))
	{
		swap_top(info->a);
		write(1, "sa\n", 3);
	}
}

void	sort_more(t_info *info)
{
	while (info->a->status > 3)
	{
		push_top(info->b, info->a);
		write(1, "pb\n", 3);
	}
	sort_few(info);
}

int		main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;

	info.a = &a; // need to recode the init_stack and creat_stack f afin de faire присваивание
	info.b = &b;
	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		if (!is_sorted(&a))
		{
			index_stack(info.a); // given an index to each element of the stack
			if (argc <= 4)
				sort_few(&info);
			else if (argc <= 10)
				sort_more(&info);
			else
				sort_clever(&info);
			move_bestone(&info);
		}
	}
	free(a.data);
	free(b.data);
	return (0);
}
