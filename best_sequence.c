/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int			index_len_max(int *len, int size)
{
	int		len_max;
	int		i;
	int		index;

	i = 0;
	index = 0;
	len_max = len[i];
	while (i < size)
	{
		if (len[i] > len_max)
		{
			len_max = len[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		check_sequence(int *data, int *len, int size)
{
	int		i;
	int		j;

	i = size;
	while (i >= 0)
	{
		len[i] = 1;
		j = size - 1;
		while (j >= i + 1)
		{
			if ((data[j] < data[i]) && (len[j] + 1 > len[i]))
				len[i] = len[j] + 1;
			j--;
		}
		i--;
	}
	return (len[index_len_max(len, size)]);
}

int		*make_sequence(int *len, int *data, int len_size, int index_max)
{
	int		*sequence;
	int		i;
	int		j;
	int		index;

	sequence = malloc(len[index_max] * sizeof(int));
	if (sequence)
	{
		i = index_max;
		j = 1;
		index = index_max;
		sequence[0] = data[index];
		while (i < len_size)
		{
			if ((len[i] == len[index_max] - j) && (data[i] < data[index]))
			{
				sequence[j] = data[i];
				index = i;
				j++;
			}
			i++;
		}
	}
	return (sequence);
}

t_stack	*best_sequence_simple(t_stack *stack)
{
	int			*len;
	t_stack		*sorted_a;

	len = malloc(stack->status * sizeof(int));
	sorted_a = malloc(sizeof(t_stack));
	if (!len || !sorted_a)
		display_error();
	sorted_a->size = check_sequence(stack->data, len, stack->status);
	sorted_a->data = make_sequence(len, stack->data, stack->status, index_len_max(len, stack->status));
	if (!sorted_a->data)
		display_error();
	sorted_a->status = sorted_a->size;
	free(len);
	return (sorted_a);
}

t_stack	*best_sequence(t_stack *stack)
{
	int			*len;
	t_stack		*sorted_a;
	int			new_sorted_size;
	int			i;

	len = malloc(stack->status * sizeof(int));
	sorted_a = malloc(sizeof(t_stack));
	if (!len || !sorted_a)
		display_error();
	i = 0;
	sorted_a->size = 0;
	while (i < stack->status)
	{
		new_sorted_size = check_sequence(stack->data, len, stack->status - 1);
		if (new_sorted_size > sorted_a->size)
		{
			sorted_a->data = make_sequence(len, stack->data, stack->status, index_len_max(len, stack->status));
			if (!sorted_a->data)
				display_error();
			sorted_a->size = new_sorted_size;
			sorted_a->status = sorted_a->size;
		}
		i++;
		rotate_stack(stack);
	}
	free(len);
	return (sorted_a);
}
