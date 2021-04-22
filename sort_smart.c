/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sort_smart.h"

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
