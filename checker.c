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

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		create_stacks(argv, argc - 1, &a, &b);
		checker(&a, &b);
	}
	return (0);
}
