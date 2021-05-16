/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int		find_min(t_stack *stack)
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
