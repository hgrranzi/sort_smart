/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void		swap_top(t_stack *stack)
{
	int		tmp;

	if (stack->status > 1)
	{
		tmp = stack->data[stack->status - 1];
		stack->data[stack->status - 1] = stack->data[stack->status - 2];
		stack->data[stack->status - 2] = tmp;
	}
}

void		push_top(t_stack *a, t_stack *b)
{
	if (b->status > 0)
		push(a, (pop(b)));
}

void		rotate_stack(t_stack *stack)
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

void		reverse_rotate_stack(t_stack *stack)
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

void		update_history(t_stack *history, int element)
{
	if (is_full(history))
	{
		reverse_rotate_stack(history);
		history->status--;
	}
	push(history, element);
}

void		exec_cmd(char *line, t_stack *a, t_stack *b, t_stack *history)
{
	if (strcmp(line, "sa") == 0)
	{
		swap_top(a);
		update_history(history, SA);
	}
	else if (strcmp(line, "sb") == 0)
	{
		swap_top(b);
		update_history(history, SB);
	}
	else if (strcmp(line, "ss") == 0)
	{
		swap_top(a);
		swap_top(b);
		update_history(history, SS);
	}
	else if (strcmp(line, "pa") == 0)
	{
		push_top(a, b);
		update_history(history, PA);
	}
	else if (strcmp(line, "pb") == 0)
	{
		push_top(b, a);
		update_history(history, PB);
	}
	else if (strcmp(line, "ra") == 0)
	{
		rotate_stack(a);
		update_history(history, RA);
	}
	else if (strcmp(line, "rb") == 0)
	{
		rotate_stack(b);
		update_history(history, RB);
	}
	else if (strcmp(line, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
		update_history(history, RR);
	}
	else if (strcmp(line, "rra") == 0)
	{
		reverse_rotate_stack(a);
		update_history(history, RRA);
	}
	else if (strcmp(line, "rrb") == 0)
	{
		reverse_rotate_stack(b);
		update_history(history, RRB);
	}
	else if (strcmp(line, "rrr") == 0)
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
		update_history(history, RRR);
	}
	else
		display_error();
}
