/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int		find_index_max(t_stack *stack)
{
	int	i;
	int	current_max;
	int	index_max;

	i = stack->status - 1;
	current_max = -INT_MAX;
	index_max = i;

	while (i >= 0)
	{
		if (stack->data[i] > current_max)
		{
			current_max = stack->data[i];
			index_max = i;
		}
		i--;
	}
	return (index_max);
}

int			is_in_sequence(t_stack *sorted, int num)
{
	int		i;

	i = 0;
	while (i < sorted->status)
	{
		if (sorted->data[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void		check_push(t_info *info, t_stack *sorted)
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
		if (new_sequence_size > sorted->status)
		{
			push(info->cmd, PA);
			free(sorted->data);
			sorted->status = new_sequence_size;
			sorted->data = make_sequence(len, info->a->data, info->a->status, index_len_max(len, info->a->status));
		}
		else
			push_top(info->b, info->a);
	}
}

void		check_swaps(t_info *info, t_stack *sorted)
{
	t_stack	*new_sorted;

	swap_top(info->a);
	new_sorted = best_sequence(info->a);
	if (new_sorted->status > sorted->status)
	{
		push(info->cmd, SA);
		//write(1, "ha\n", 3);
		//destroy_stack(sorted);
		sorted = new_sorted;
	}
	else
	{
		swap_top(info->a);
		//destroy_stack(new_sorted);
	}
}

int		choose_rotate(t_stack *a, t_stack *sorted) // для каждого числа в b считаем количество шагов до нужной позиции в а
{
	int		rot;
	int		reverse_rot;
	int		i;

	rot = 0;
	i = a->status - 1;
	while (is_in_sequence(sorted, a->data[i]))
		i--;
	rot = (a->status - 1) - i;
	i = 0;
	while (is_in_sequence(sorted, a->data[i]))
		i++;
	reverse_rot = 1 + i;
	if (reverse_rot < rot)
		return (-reverse_rot);
	return (rot);
}

void		rotate_a(t_info *info, int moves)
{
	while (moves > 0)
	{
		rotate_stack(info->a);
		push(info->cmd, RA);
		moves--;
	}
	while (moves < 0)
	{
		reverse_rotate_stack(info->a);
		push(info->cmd, RRA);
		moves++;
	}
}

void		rotate_b(t_info *info, int moves)
{
	while (moves > 0)
	{
		rotate_stack(info->b);
		push(info->cmd, RB);
		moves--;
	}
	while (moves < 0)
	{
		reverse_rotate_stack(info->b);
		push(info->cmd, RRB);
		moves++;
	}
}

void	sort_few_b(t_info *info)
{
	if (info->b->status == 2
	|| ((info->b->data[0] > info->b->data[1]) && (info->b->data[0] < info->b->data[2]))
	|| ((info->b->data[1] > info->b->data[2]) && (info->b->data[1] < info->b->data[0]))
	|| ((info->b->data[2] > info->b->data[0]) && (info->b->data[2] < info->b->data[1])))
	{
		swap_top(info->b);
		push(info->cmd, SB);
	}
}

t_stack	*initial_sort_b(t_info *info)
{
	t_stack		*sorted_b;
	int		first_one_b;
	t_moves	bestone;
	int		rot;
	int		reverse_rot;

	bestone.a = 0;
	bestone.b = 0;
	sort_few_b(info);
	first_one_b = find_index_max(info->b);
	rot = info->b->status - 1 - first_one_b;
	reverse_rot = first_one_b + 1;
	if (rot > reverse_rot)
		bestone.b = -reverse_rot;
	else
		bestone.b = rot;
	exec_rotate(info, &bestone);
	exec_reverse_rotate(info, &bestone);
	sorted_b = malloc(sizeof(t_stack));
	if (!sorted_b)
		display_error();
	sorted_b->data = copy_stack_data(info->b);
	if (!sorted_b->data)
		display_error();
	sorted_b->size = info->b->size;
	sorted_b->status = info->b->status;
	return (sorted_b);
}

void		move_unsorted(t_info *info, t_stack *sorted)
{
	int		moves;
	t_stack *sorted_b;

	sorted_b = NULL;
	//print_stack(info->a);
	//check_swaps(info, sorted);
	while (info->a->status > sorted->size && info->b->status < 3)
	{
		moves = choose_rotate(info->a, sorted);
		rotate_a(info, moves);
		push_top(info->b, info->a);
		push(info->cmd, PB);
		//check_swaps(info, sorted);
	}
	if (info->a->status > sorted->size)
		sorted_b = initial_sort_b(info);
	//print_stack(sorted_b);
	//check_swaps(info, sorted);
	while (info->a->status > sorted->size)
	{
		moves = choose_rotate(info->a, sorted);
		rotate_a(info, moves);
		push_top(info->b, info->a);
		push(info->cmd, PB);
		//check_swaps(info, sorted);
	}
	//print_stack(info->a);
}
