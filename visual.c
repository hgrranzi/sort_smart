/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void				put_pxl(t_data *data, int x, int y, int color)
{
	char			*dst;

	if (x >= 0 && y >= 0)
	{
		dst = data->visual->addr +
		(y * data->visual->line + x * (data->visual->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	fill_background(t_data *data)
{
	int	x;
	int	y;

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

void	run_visual(t_data *data, t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	fill_background(data);
	x = 0;
	while (x < a->status - 1)
	{
		y = 0;
		while (y < a->data[x])
		{
			put_pxl(data, x, y, 0xf0f8ff);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->visual->img, 0, 0);
	return ;
}

void	get_visual(t_data *data)
{
	data->visual->img = mlx_new_image(data->mlx_p, WIN_W, WIN_H);
	if (data->visual->img == NULL)
		display_error();
	data->visual->addr = mlx_get_data_addr(data->visual->img,
		&data->visual->bpp, &data->visual->line, &data->visual->endian);
	return ;
}
