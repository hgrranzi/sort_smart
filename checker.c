/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void	checker_visual(t_stack *a, t_stack *b)
{
	t_data	data;
	t_image	visual;
	t_image	back;

	data.a = a;
	data.b = b;
	data.visual = &visual;
	data.back = &back;
	if (!(data.mlx_p = mlx_init()) || (!(data.win_p = mlx_new_window(data.mlx_p, WIN_W, WIN_W, "checker"))))
		display_error();
	get_visual(&data);
	fill_background(&data);
	draw_stack(&data);
	mlx_hook(data.win_p, 2, 1L << 0, press_key, &data);
	mlx_put_image_to_window(data.mlx_p, data.win_p, data.visual->img, 0, 0);
	mlx_loop_hook(data.mlx_p, run_visual, &data);
	mlx_loop(data.mlx_p);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		exec_cmd(line, a, b);
		free(line);
	}
	free(line);
	if (is_empty(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		if (aka_strcmp(argv[1], "-v") == 0 && argc > 2)
		{
			create_stacks(&argv[1], argc - 2, &a, &b);
			checker_visual(&a, &b);
		}
		create_stacks(argv, argc - 1, &a, &b);
		checker(&a, &b);
		destroy_stack(&a);
		destroy_stack(&b);
	}
	return (0);
}
