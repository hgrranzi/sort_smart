/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

int	press_key(int key, t_data *data)
{
	if (key == 35)
		data->pause = 1;
	if (key == 49)
		data->pause = 0;
	if (key == 124 || key == 49)
		data->play = 1;
	if (key == 125)
		data->speed_delay = 1;
	else if (key == 126)
		data->speed_delay = 0;
	if (key == 53)
		exit(0);
	return (0);
}

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = data->visual->addr + (y * data->visual->line + x * (data->visual->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	*get_texls(t_image *texture, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int *)(texture->addr + (y * texture->line + x * (texture->bpp / 8)));
	return (color);
}

void	fill_background(t_data *data)
{
	int				x;
	int				y;
	int				color;

	y = 0;
	while (y < WIN_W)
	{
		x = 0;
		while (x < WIN_W)
		{
			color = *get_texls(data->back, x, y);
			put_pxl(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(t_data *data, int line_h, int start_y, int start_x)
{
	int		x;
	int		y;
	int		i;

	y = start_y;
	x = start_x;
	i = 0;
	if (line_h < 1)
		line_h = 1;
	while (i < data->stripe_w / 2)
	{
		y = start_y;
		while (y > start_y - line_h)
		{
			put_pxl(data, x, y, 0xf0f8ff);
			y--;
		}
		x++;
		i++;
	}
}

void	draw_stack(t_data *data)
{
	int		i;
	int		j;

	i = data->b->status - 1;
	j = 0;
	while (i >= 0)
	{
		draw_line(data, (int)(data->stripe_h * (data->b->data[i] + data->factor)), WIN_W / 2 - 1 - PADDING, (int)(data->stripe_w * j) + PADDING);
		i--;
		j++;
	}
	i = data->a->status - 1;
	j = 0;
	while (i >= 0)
	{
		draw_line(data, (int)(data->stripe_h * (data->a->data[i] + data->factor)), WIN_W - 1 - PADDING, (int)(data->stripe_w * j) + PADDING);
		i--;
		j++;
	}
}

int	run_visual(t_data *data)
{
	char	*line;
	int		cmd;

	line = NULL;
	cmd = 0;
	if (is_empty(data->b) && is_sorted(data->a))
	{
		sleep(8);
		write(1, "OK\n", 3);
		exit(0);
	}
	fill_background(data);
	if (data->play && get_next_line(0, &line))
		exec_cmd(line, data->a, data->b);
	if (data->pause)
		data->play = 0;
	draw_stack(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->visual->img, 0, 0);
	if (data->speed_delay)
		usleep(SPEED_DELAY);
	return (0);
}

void	get_visual(t_data *data)
{
	int		i;

	i = 0;
	data->visual->img = mlx_new_image(data->mlx_p, WIN_W, WIN_W);
	if (data->visual->img == NULL)
		display_error();
	data->visual->addr = mlx_get_data_addr(data->visual->img,
		&data->visual->bpp, &data->visual->line, &data->visual->endian);
	data->back->img = mlx_xpm_file_to_image(data->mlx_p, IMG_PATH, &data->back->w, &data->back->h);
	if (data->back->img == NULL)
		display_error();
	data->back->addr = mlx_get_data_addr(data->back->img,
		&data->back->bpp, &data->back->line, &data->back->endian);
	data->stripe_w = (1.0 * WIN_W - 2 * PADDING) / data->a->status;
	data->factor = find_min(data->a) * -1;
	data->stripe_h = ((1.0 * WIN_W - 2 * PADDING) / (find_max(data->a) - find_min(data->a))) / 2;
	data->speed_delay = 0;
	data->play = 1;
	data->pause = 0;
}
