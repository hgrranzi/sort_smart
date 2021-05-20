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

int	find_min_min(t_stack *stack)
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
