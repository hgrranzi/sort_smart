/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "utils.h"

int	find_max(t_stack *stack)
{
	int	i;
	int	current_max;

	i = stack->status - 1;
	current_max = -INT_MAX;
	while (i >= 0)
	{
		if (stack->data[i] > current_max)
			current_max = stack->data[i];
		i--;
	}
	return (current_max);
}

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

int	find_min(t_stack *stack)
{
	int	i;
	int	current_min;

	i = stack->status - 1;
	current_min = INT_MAX;
	while (i >= 0)
	{
		if (stack->data[i] < current_min)
			current_min = stack->data[i];
		i--;
	}
	return (current_min);
}

int		find_index_min(t_stack *stack)
{
	int	i;
	int	current_min;
	int	index_min;

	i = stack->status - 1;
	current_min = INT_MAX;
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
