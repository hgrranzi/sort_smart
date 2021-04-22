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

void		check_sequence(int *data, int *len, int size)
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

void		best_sequence(t_info *info)
{
	int		*len;
	int		*array;
	int		*sequence;

	len = malloc(info->a->status * sizeof(int));
	array = malloc(info->a->status * sizeof(int));
	if (!len || !array)
		display_error();
	check_sequence(info->a->data, len, info->a->status);
	sequence = make_sequence(len, info->a->data, info->a->status, index_len_max(len, info->a->status));
	if (!sequence)
		display_error();
}

void		sort_clever(t_info *info)
{
	index_stack(info->a); // given an index to each element of the stack
	best_sequence(info); // находим наибольшую восходящую последовательность
	// перекидываем в б все кроме последовательности
		// стоит ли выполнить двойную команду
		// проверить не расширилась ли последовательность
	// перекидываем обратно в а
	// находим наибольшую убывающую последовательность
		// для каждого числа в b считаем количество шагов до нужной позиции в а
		// выполняем шаги для того, у кого их меньше
	sort_stupid(info);
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
