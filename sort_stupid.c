/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

char	**init_commands(char **commands, int size)
{
	commands = malloc((size + 1) * sizeof(char *));
	if (!commands)
		return (NULL);
	commands[NOT_CMD] = strdup("");
	commands[SA] = strdup("sa\n");
	commands[SB] = strdup("sb\n");
	commands[SS] = strdup("ss\n");
	commands[PA] = strdup("pa\n");
	commands[PB] = strdup("pb\n");
	commands[RA] = strdup("ra\n");
	commands[RB] = strdup("rb\n");
	commands[RR] = strdup("rr\n");
	commands[RRA] = strdup("rra\n");
	commands[RRB] = strdup("rrb\n");
	commands[RRR] = strdup("rrr\n");
	//here should be a check for all those f
	return (commands);
}

void	print_commands(t_stack *stack, char **commands)
{
	int	i;

	i = 0;
	while (i < stack->status)
	{
		printf("%s", commands[stack->data[i]]);
		i++;
	}
	stack->status = 0;
}

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

void	sort_stupid(t_info *info)
{
	int	index_min;

	index_min = info->b->status;
	while (info->a->status)
	{
		index_min = find_min(info->a);
		while (index_min < info->a->status - 1)
		{
			push(info->cmd, RA);
			rotate_stack(info->a);
			index_min++;
		}
		push_top(info->b, info->a);
		push(info->cmd, PB);
	}
	while (info->b->status)
	{
		push_top(info->a, info->b);
		push(info->cmd, PA);
	}
	print_commands(info->cmd, info->commands);
}
