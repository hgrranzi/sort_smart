/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

int			*copy_stack_data(t_stack *stack)
{
	int		*new_data;
	int		i;

	new_data = malloc(stack->status);
	i = 0;
	if (new_data)
		while (i < stack->status)
		{
			new_data[i] = stack->data[i];
			i++;
		}
	return (new_data);
}

int			need_swap(int *a, int *b, int flag)
{
	int		tmp;

	if (*a > *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		flag = 1;
	}
	return (flag);
}

void		sort_array(int	*array, int size)
{
	int		start;
	int		end;
	int		flag;
	int		i;

	start = 0;
	end  = size - 1;
	flag = 1;
	while ((start < end) && flag)
	{
		i = start;
		flag = 0;
		while (i < end)
		{
			flag = need_swap(&array[i], &array[i + 1], flag);
			i++;
		}
		end--;
		i = end;
		while (i > start)
		{
			flag = need_swap(&array[i - 1], &array[i], flag);
			i--;
		}
		start++;
	}
}

void		index_stack(t_stack *stack)
{
	int		*array;
	int		i;
	int		j;

	array = copy_stack_data(stack);
	if (!array)
		display_error();
	sort_array(array, stack->status);
	i = 0;
	while (i < stack->status)
	{
		j = 0;
		while (j < stack->status)
		{
			if (stack->data[i] == array[j])
			{
				stack->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(array);
	array = NULL;
}

void		sort_clever(t_info *info)
{
	int		i;

	i = 0;
	index_stack(info->a); // вместо каждого числа в стеке записываем его номер в отсортированной последовательности
	//best_sequence(info->a); // находим наибольшую восходящую последовательность, записываем ее границы
	// перекидываем в б все кроме последовательности
		// стоит ли выполнить двойную команду
		// проверить не расширилась ли последовательность
	// перекидываем обратно в а
	// находим наибольшую убывающую последовательность
		// для каждого числа в b считаем количество шагов до нужной позиции в а
		// выполняем шаги для того, у кого их меньше
	//print_stack(info->a);
	//print_stack(info->a);
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

	info.a = &a; // need to recode the init_stack and creat_stuck f afin de faire присваивание
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
