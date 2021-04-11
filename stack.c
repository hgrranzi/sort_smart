/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

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

void	push(t_stack *stack, int element)
{
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

void	print_stack(t_stack *stack) // probably will be better with my own printf
{
	int	i;

	i = 0;
	write(1, "---\n", 4);
	while (i < stack->status)
	{
		aka_putchar('|');
		aka_putnbr(stack->data[i]);
		aka_putchar('|');
		aka_putchar('\n');
		i++;
	}
	write(1, "---\n", 4);
}
