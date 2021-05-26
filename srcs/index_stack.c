/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int	*copy_stack_data(t_stack *stack)
{
	int		*new_data;
	int		i;

	new_data = malloc(stack->status * sizeof(int));
	i = 0;
	if (new_data)
	{
		while (i < stack->status)
		{
			new_data[i] = stack->data[i];
			i++;
		}
	}
	return (new_data);
}

void	copy_stack(t_stack *dst, t_stack *src)
{
	dst->data = copy_stack_data(src);
	if (!dst->data)
		display_error();
	dst->size = src->status;
	dst->status = src->status;
}

static int	need_swap(int *a, int *b, int flag)
{
	int		tmp;

	if (*a > *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		flag = 1;
	}
	return (flag);
}

void	sort_array(int	*array, int end)
{
	int		start;
	int		flag;
	int		i;

	start = 0;
	flag = 1;
	end--;
	while ((start < end) && flag)
	{
		i = start;
		flag = 0;
		while (i < end)
		{
			flag = need_swap(&array[i], &array[i + 1], flag);
			i++;
		}
		end--;
		i = end;
		while (i > start)
		{
			flag = need_swap(&array[i - 1], &array[i], flag);
			i--;
		}
		start++;
	}
}

void	index_stack(t_stack *stack)
{
	int		*array;
	int		i;
	int		j;

	array = copy_stack_data(stack);
	if (!array)
		display_error();
	sort_array(array, stack->status);
	i = 0;
	while (i < stack->status)
	{
		j = 0;
		while (j < stack->status)
		{
			if (stack->data[i] == array[j])
			{
				stack->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(array);
	array = NULL;
}
