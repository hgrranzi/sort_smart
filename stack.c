/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "stack.h"

int		*init_stack(t_stack *stack, int size)
{
	stack->data = malloc(size * sizeof(int));
	stack->status = 0;
	stack->size = size;
	return (stack->data); // if malloc fails the function returns null
}

int		is_empty(t_stack *stack)
{
	return (stack->status == 0);
}

int		is_full(t_stack *stack)
{
	return (stack->status == stack->size);
}

int			is_duplicate(int nbr, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->status)
	{
		if (stack->data[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int			is_sorted(t_stack *stack)
{
	int		i;

	i = stack->status - 1;
	while (i > 0)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	resize_stack(t_stack *stack)
{
	int	*tmp_data;
	int	i;

	stack->size += PLUS_SIZE;
	tmp_data = malloc((stack->size) * sizeof(int));
	if (!tmp_data)
		display_error();
	i = 0;
	while (i < stack->status)
	{
		tmp_data[i] = stack->data[i];
		i++;
	}
	free(stack->data);
	stack->data = tmp_data;
}

void	push(t_stack *stack, int element)
{
	if (is_full(stack))
		resize_stack(stack);
	stack->data[stack->status] = element;
	stack->status++;
}

int		pop(t_stack *stack)
{
	int	popped;

	popped = stack->data[stack->status- 1];
	stack->status--;
	return (popped);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->status = 0;
	stack->size = 0;
}

void	display_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
