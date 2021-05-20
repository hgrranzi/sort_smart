/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int	positive(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	check_moves(t_stack *a, t_stack *b, t_moves index, t_moves *moves)
{
	t_moves	rot;
	t_moves	reverse_rot;

	rot.a = a->status - 1 - index.a;
	reverse_rot.a = index.a + 1;
	rot.b = b->status - 1 - index.b;
	reverse_rot.b = index.b + 1;

	if (rot.a > reverse_rot.a)
	{
		moves->a = -reverse_rot.a;
		if (rot.b == reverse_rot.b)
			moves->b = -reverse_rot.b;
	}
	if (rot.a < reverse_rot.a)
	{
		moves->a = rot.a;
		if (rot.b == reverse_rot.b)
			moves->b = rot.b;
	}
	if (rot.b > reverse_rot.b)
	{
		moves->b = -reverse_rot.b;
		if (rot.a == reverse_rot.a)
			moves->a = -reverse_rot.a;
	}
	if (rot.b < reverse_rot.b)
	{
		moves->b = rot.b;
		if (rot.a == reverse_rot.a)
			moves->a = rot.a;
	}
}

int	count_moves(int b_moves, int a_moves)
{
	int		moves;

	if ((b_moves < 0 && a_moves < 0) || (b_moves > 0 && a_moves > 0))
		moves = max(positive(b_moves), positive(a_moves));
	else
		moves = positive(b_moves) + positive(a_moves);
	return (moves);
}
