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

unsigned int		*get_texls(t_image *texture, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int *)(texture->addr +
	(y * texture->line + x * (texture->bpp / 8)));
	return (color);
}

void		fill_background(t_data *data)
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

void		draw_stripe(t_data *data, int stripe_h, int start_y, int start_x)
{
	int		x;
	int		y;
	int		i;

	y = start_y;
	x = start_x;
	i = 0;
	while (i < data->stripe_w / 2)
	{
		y = start_y;
		while (y > start_y - stripe_h)
		{
			put_pxl(data, x, y, 0xf0f8ff);
			y--;
		}
		x++;
		i++;
	}
}

void		draw_stack(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->a->status - 1)
	{
		draw_stripe(data, (int)(data->stripe_h * data->a->data[i]), WIN_W / 2 - 1, i * data->stripe_w);
		i++;
	}
	i = 0;
	while (i < data->b->status - 1)
	{
		draw_stripe(data, (int)(data->stripe_h * data->b->data[i]), WIN_W - 1, i * data->stripe_w);
		i++;
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
		free(line);
		line = NULL;
		draw_stack(data);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->visual->img, 0, 0);
	}
	else
	{
		if (is_empty(data->b) && is_sorted(data->a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}

void		get_visual(t_data *data)
{
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
	return ;
}
