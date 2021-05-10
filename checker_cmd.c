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

int			line_to_cmd(char *line)
{
	int		cmd;

	if (strcmp(line, "sa") == 0)
		cmd = SA;
	else if (strcmp(line, "sb") == 0)
		cmd = SB;
	else if (strcmp(line, "ss") == 0)
		cmd = SS;
	else if (strcmp(line, "pa") == 0)
		cmd = PA;
	else if (strcmp(line, "pb") == 0)
		cmd = PB;
	else if (strcmp(line, "ra") == 0)
		cmd = RA;
	else if (strcmp(line, "rb") == 0)
		cmd = RB;
	else if (strcmp(line, "rr") == 0)
		cmd = RR;
	else if (strcmp(line, "rra") == 0)
		cmd = RRA;
	else if (strcmp(line, "rrb") == 0)
		cmd = RRB;
	else if (strcmp(line, "rrr") == 0)
		cmd = RRR;
	else
		cmd = NOT_CMD;
	free(line);
	line = NULL;
	return (cmd);
}

void		exec_cmd(int cmd, t_stack *a, t_stack *b, t_stack *history)
{
	if (cmd == SA)
		swap_top(a);
	else if (cmd == SB)
		swap_top(b);
	else if (cmd == SS)
	{
		swap_top(a);
		swap_top(b);
	}
	else if (cmd == PA)
		push_top(a, b);
	else if (cmd == PB)
		push_top(b, a);
	else if (cmd == RA)
		rotate_stack(a);
	else if (cmd == RB)
		rotate_stack(b);
	else if (cmd == RR)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (cmd == RRA)
		reverse_rotate_stack(a);

	else if (cmd == RRB)
	{
		reverse_rotate_stack(b);
		update_history(history, RRB);
	}
	else if (cmd == RRR)
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else
		display_error();
	update_history(history, cmd);
}

void		exec_contre_cmd(t_stack *a, t_stack *b, t_stack *history, t_stack *forward)
{
	int		cmd;

	if (is_empty(history))
		return ;
	cmd = pop(history);
	if (cmd == SA)
		swap_top(a);
	else if (cmd == SB)
		swap_top(b);
	else if (cmd == SS)
	{
		swap_top(a);
		swap_top(b);
	}
	else if (cmd == PA)
		push_top(b, a);
	else if (cmd == PB)
		push_top(a, b);
	else if (cmd == RA)
		reverse_rotate_stack(a);
	else if (cmd == RB)
		reverse_rotate_stack(b);
	else if (cmd == RR)
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else if (cmd == RRA)
		rotate_stack(a);
	else if (cmd == RRB)
		rotate_stack(b);
	else if (cmd == RRR)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	push(forward, cmd);
}
