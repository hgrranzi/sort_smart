/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

void	print_cmd(t_stack *stack, char **commands)
{
	int	i;

	i = 0;
	while (i < stack->status - 1)
	{
		puts(commands[pop(stack)]);
		i++;
	}
}

int		find_min(t_stack *stack)
{
	int	i;
	int	current_min;
	int	index_min;

	i = stack->status - 1;
	current_min = INT32_MAX;
	index_min = i;

	while (i >= 0)
	{
		if (stack->data[i] < current_min)
		{
			current_min = stack->data[i];
			index_min = i;
		}
		i--;
	}
	return (index_min);
}

void	sort_stupid(t_info *info)
{
	int	index_min;

	index_min = info->b->status;
	while (info->a->status)
	{
		index_min = find_min(info->a);
		while (index_min < info->a->status - 1)
		{
			push(info->cmd, RA);
			rotate_stack(info->a);
			index_min++;
		}
		push_top(info->b, info->a);
		push(info->cmd, PB);
	}
	while (info->b->status)
	{
		push_top(info->a, info->b);
		push(info->cmd, PA);
	}

}
