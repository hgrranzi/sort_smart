/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

t_borders	take_sequence(t_stack *stack, int i)
{
	t_borders	new_sequence;

	new_sequence.start = i;
	while (i > 0)
	{
		if ((stack->data[i] + 1) > stack->data[i - 1])
			break ;
		i--;
	}
	new_sequence.end = i;
	return (new_sequence);
}

void		best_sequence(t_info *info)
{
	int		i;
	t_borders	sequence;
	t_borders	tmp;

	i = info->a->status - 1;
	sequence.start = info->a->status - 1;
	sequence.end = info->a->status - 1;
	while (i >= 0)
	{
		tmp = take_sequence(info->a, i);
		if ((tmp.start - tmp.end) >= (sequence.start - sequence.end))
			sequence = tmp;
		i--;
	}

	i = sequence.start;
	while (i >= sequence.end)
	{
		printf("%d ", info->a->data[i]);
		i--;
	}
	printf("\nborders%d %d", sequence.start, sequence.end);
}

void		sort_clever(t_info *info)
{
	int		i;

	i = 0;
	index_stack(info->a); // given an index to each element of the stack
	best_sequence(info); // находим наибольшую восходящую последовательность, записываем ее границы
	// перекидываем в б все кроме последовательности
		// стоит ли выполнить двойную команду
		// проверить не расширилась ли последовательность
	// перекидываем обратно в а
	// находим наибольшую убывающую последовательность
		// для каждого числа в b считаем количество шагов до нужной позиции в а
		// выполняем шаги для того, у кого их меньше
	//print_stack(info->a);
	//print_stack(info->a);
	//sort_stupid(info);
	return ;
}

int			main(int argc, char **argv)
{
	t_info	info;
	t_stack	a;
	t_stack	b;
	t_stack	cmd;
	char	**commands = NULL;

	info.a = &a; // need to recode the init_stack and creat_stack f afin de faire присваивание
	info.b = &b;
	info.cmd = &cmd;
	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		if (!is_sorted(&a))
		{
			cmd.data = init_stack(&cmd, 20 * argc); // that should realloc when necessary or be cleaned
			info.commands = init_commands(commands, CMD_NUMBER);
			if (!cmd.data || !info.commands)
				display_error();
			sort_clever(&info);
		}
		//print_stack(info.a);
	}
	free(a.data); // сократить код
	free(b.data);
	free(cmd.data);
	return (0);
}
