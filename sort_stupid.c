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

void	sort_stupid(t_stack *a, t_stack *b, t_stack *cmd)
{
	int	index_min;

	index_min = b->status;
	while (a->status)
	{
		index_min = find_min(a);
		while (index_min < a->status - 1)
		{
			push(cmd, RA);
			rotate_stack(a);
			index_min++;
		}
		push_top(b, a);
		push(cmd, PB);
	}
	while (b->status)
	{
		push_top(a, b);
		push(cmd, PA);
	}

}
