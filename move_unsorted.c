/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int	is_in_sequence(t_stack *sorted, int num)
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

int	choose_rotate(t_stack *a, t_stack *sorted) // для каждого числа в b считаем количество шагов до нужной позиции в а
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

void	rotate_a(t_info *info, int moves)
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

void	move_unsorted(t_info *info, t_stack *sorted)
{
	int		moves;

	if (info->flag)
		move_bestone_b(info, sorted);
	while (info->a->status > sorted->size)
	{
		moves = choose_rotate(info->a, sorted);
		rotate_a(info, moves);
		push_top(info->b, info->a);
		push(info->cmd, PB);
	}
}
