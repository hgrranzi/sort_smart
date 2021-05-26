/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

void	sort_few(t_info *info)
{
	if (info->a->status == 2
		|| ((info->a->data[2] > info->a->data[1])
			&& (info->a->data[2] < info->a->data[0]))
		|| ((info->a->data[1] > info->a->data[0])
			&& (info->a->data[1] < info->a->data[2]))
		|| ((info->a->data[0] > info->a->data[2])
			&& (info->a->data[0] < info->a->data[1])))
	{
		swap_top(info->a);
		push(info->cmd, SA);
	}
}

void	sort_more(t_info *info)
{
	while (info->a->status > 3)
	{
		push_top(info->b, info->a);
		push(info->cmd, PB);
	}
	sort_few(info);
}

void	sort_clever(t_info *info)
{
	t_stack	*sorted;

	sorted = best_sequence(info->a); // находим наибольшую восходящую последовательность
	move_unsorted(info, sorted);
	destroy_stack(sorted);
	free(sorted);
	return ;
}
