/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void		put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = data->visual->addr +
		(y * data->visual->line + x * (data->visual->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void		fill_background(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			put_pxl(data, x, y, 0x2c226e);
			y++;
		}
		x++;
	}
}

void		draw_stack(t_data *data, t_stack *stack)
{
	int		x;
	int		y;

	x = 0;
	while (x < stack->status - 1)
	{
		y = 0;
		while (y < stack->data[x])
		{
			put_pxl(data, x, y, 0xf0f8ff);
			y++;
		}
		x++;
	}
}

int			run_visual(t_data *data)
{
	char	*line;

	line = NULL;
	fill_background(data);
	if (get_next_line(0, &line))
	{
		exec_cmd(line, data->a, data->b);
		usleep(SPEED_DELAY);
		free(line);
		line = NULL;
		draw_stack(data, data->a);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->visual->img, 0, 0);
	}
	else
	{
		if (is_empty(data->b) && is_sorted(data->a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		exit(0);
	}
	return (0);
}

void		get_visual(t_data *data)
{
	data->visual->img = mlx_new_image(data->mlx_p, WIN_W, WIN_H);
	if (data->visual->img == NULL)
		display_error();
	data->visual->addr = mlx_get_data_addr(data->visual->img,
		&data->visual->bpp, &data->visual->line, &data->visual->endian);
	return ;
}
