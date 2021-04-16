/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void		checker(t_stack *a, t_stack *b)
{
	t_data	data;
	t_image	visual;
	char	*line;

	data.visual = &visual;
	data.a = a;
	data.b = b;
	if (!(data.mlx_p = mlx_init()) || (!(data.win_p = mlx_new_window(data.mlx_p, WIN_W, WIN_H, "checker"))))
		display_error();
	get_visual(&data);
	mlx_hook(data.win_p, 17, 0, run_visual, 0);
	mlx_loop_hook(data.mlx_p, run_visual, &data);
	mlx_loop(data.mlx_p);
}

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		checker(&a, &b);
		print_stack(&a);
		print_stack(&b);
	}
	return (0);
}
