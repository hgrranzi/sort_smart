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

t_sorted	*best_sequence(t_stack *stack)
{
	int			*len;
	t_sorted	*sorted;

	len = malloc(stack->status * sizeof(int));
	sorted = malloc(sizeof(t_sorted));
	if (!len || !sorted)
		display_error();
	sorted->size = check_sequence(stack->data, len, stack->status);
	sorted->sequence = make_sequence(len, stack->data, stack->status, index_len_max(len, stack->status));
	if (!sorted->sequence)
		display_error();
	free(len);
	return (sorted);
}
