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
