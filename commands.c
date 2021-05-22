/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

char	**init_commands(char **commands, int size)
{
	int		i;

	i = 0;
	commands = malloc((size + 1) * sizeof(char *));
	if (!commands)
		return (NULL);
	commands[NOT_CMD] = aka_strdup("");
	commands[SA] = aka_strdup("sa\n");
	commands[SB] = aka_strdup("sb\n");
	commands[SS] = aka_strdup("ss\n");
	commands[PA] = aka_strdup("pa\n");
	commands[PB] = aka_strdup("pb\n");
	commands[RA] = aka_strdup("ra\n");
	commands[RB] = aka_strdup("rb\n");
	commands[RR] = aka_strdup("rr\n");
	commands[RRA] = aka_strdup("rra\n");
	commands[RRB] = aka_strdup("rrb\n");
	commands[RRR] = aka_strdup("rrr\n");
	while (i < size)
	{
		if (!commands[i])
			return (NULL);
		i++;
	}
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

void	destroy_commands(char **commands, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		free(commands[i]);
		commands[i] = NULL;
		i--;
	}
	free(commands);
	commands = NULL;
}
