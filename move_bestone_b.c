/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int	right_place_b(t_stack *stack, int num)
{
	int		i;
	int		index_max;
	int		min;
	int		max;

	index_max = find_index_max(stack);
	max = stack->data[index_max];
	min = find_min(stack);
	if (num > max || num < min)
		return (index_max);
	i = stack->status - 1;
	if (num > stack->data[i] && num < stack->data[0])
		return (i);
	i = stack->status - 2;
	while (i >= 0)
	{
		if (num < stack->data[i + 1] && num > stack->data[i])
			break ;
		i--;
	}
	return (i);
}

void	find_bestone_b(t_stack *a, t_stack *b, t_moves *bestone, t_stack *sorted)
{
	int		current_moves;
	int		min_moves;
	t_moves	index;
	t_moves	moves;

	index.b = b->status - 1;
	min_moves = INT_MAX;
	while (index.b >= 0)
	{
		if (is_in_sequence(sorted, b->data[index.b]))
			current_moves = INT_MAX;
		else
		{
			index.a = right_place_b(a, b->data[index.b]);
			check_moves(a, b, index, &moves);
			current_moves = count_moves(moves.b, moves.a);
		}
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			bestone->a = moves.a;
			bestone->b = moves.b;
		}
		index.b--;
	}
}

void	move_bestone_b(t_info *info, t_stack *sorted)
{
	t_moves	bestone;
	int		tmp;
	int		ha;

	bestone.a = 0;
	bestone.b = 0;
	ha = (info->a->status - sorted->status) / info->flag;
	while (ha)
	{
		find_bestone_b(info->b, info->a, &bestone, sorted);
		tmp = bestone.a;
		bestone.a = bestone.b;
		bestone.b = tmp;
		exec_rotate(info, &bestone);
		exec_reverse_rotate(info, &bestone);
		push(info->cmd, PB);
		push_top(info->b, info->a);
		ha--;
	}
}
