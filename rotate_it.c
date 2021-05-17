/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

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

void		rotate_it(t_info *info)
{
	t_moves	bestone;
	int		first_one;
	int		rot;
	int		reverse_rot;

	bestone.a = 0;
	bestone.b = 0;
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
