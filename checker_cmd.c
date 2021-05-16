/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void	swap_top(t_stack *stack)
{
	int		tmp;

	if (stack->status > 1)
	{
		tmp = stack->data[stack->status - 1];
		stack->data[stack->status - 1] = stack->data[stack->status - 2];
		stack->data[stack->status - 2] = tmp;
	}
}

void	push_top(t_stack *a, t_stack *b)
{
	if (b->status > 0)
		push(a, (pop(b)));
}

void	rotate_stack(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->status > 1)
	{
		i = stack->status - 1;
		tmp = stack->data[i];
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[i] = tmp;
	}
}

void	reverse_rotate_stack(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->status > 1)
	{
		i = 0;
		tmp = stack->data[i];
		while (i < stack->status - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[i] = tmp;
	}
}

void	exec_cmd(char *line, t_stack *a, t_stack *b)
{
	if (aka_strcmp(line, "sa") == 0)
		swap_top(a);
	else if (aka_strcmp(line, "sb") == 0)
		swap_top(b);
	else if (aka_strcmp(line, "ss") == 0)
	{
		swap_top(a);
		swap_top(b);
	}
	else if (aka_strcmp(line, "pa") == 0)
		push_top(a, b);
	else if (aka_strcmp(line, "pb") == 0)
		push_top(b, a);
	else if (aka_strcmp(line, "ra") == 0)
		rotate_stack(a);
	else if (aka_strcmp(line, "rb") == 0)
		rotate_stack(b);
	else if (aka_strcmp(line, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (aka_strcmp(line, "rra") == 0)
		reverse_rotate_stack(a);
	else if (aka_strcmp(line, "rrb") == 0)
		reverse_rotate_stack(b);
	else if (aka_strcmp(line, "rrr") == 0)
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else
		display_error();
}
