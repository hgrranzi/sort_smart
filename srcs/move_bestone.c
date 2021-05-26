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

	index_min = find_index_min(stack);
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

void	move_bestone(t_info *info)
{
	t_moves	bestone;

	bestone.a = 0;
	bestone.b = 0;
	while (info->b->status)
	{
		find_bestone(info->a, info->b, &bestone);
		exec_rotate(info, &bestone); // выполняем шаги для того, у кого их меньше
		exec_reverse_rotate(info, &bestone);
		push(info->cmd, PA);
		push_top(info->a, info->b);
	}
	rotate_it(info);
}
