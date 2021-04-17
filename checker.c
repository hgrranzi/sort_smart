/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

int		find_max(t_stack *stack)
{
	int	i;
	int	current_max;

	i = stack->status - 1;
	current_max = INT32_MIN;
	while (i >= 0)
	{
		if (stack->data[i] > current_max)
			current_max = stack->data[i];
		i--;
	}
	return (current_max);
}

void		checker(t_stack *a, t_stack *b)
{
	t_data	data;
	t_image	visual;
	t_image	back;

	data.visual = &visual;
	data.back = &back;
	data.stripe_w = WIN_W / a->status;
	data.stripe_h = 1.0 * find_max(a) / WIN_W * 2;
	data.a = a;
	data.b = b;
	if (!(data.mlx_p = mlx_init()) || (!(data.win_p = mlx_new_window(data.mlx_p, WIN_W, WIN_W, "checker"))))
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
