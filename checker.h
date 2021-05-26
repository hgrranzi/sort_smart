/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <math.h>
# include "mlx/mlx.h"
# include "utils.h"

# define CMD_NUMBER 11
# define SPEED_DELAY 20000
# define WIN_W 1080
# define PADDING 10
# define IMG_PATH "pic/red_space.xpm"

typedef enum e_cmd
{
	NOT_CMD,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_cmd;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
	int			w;
	int			h;
}				t_image;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			factor;
	float		stripe_w;
	float		stripe_h;
	void		*mlx_p;
	void		*win_p;
	t_image		*back;
	t_image		*visual;
	int			play;
	int			pause;
	int			speed_delay;
}				t_data;

void			checker(t_stack *a, t_stack *b);
void			checker_visual(t_stack *a, t_stack *b);

int				line_to_cmd(char *line);
void			exec_cmd(char *line, t_stack *a, t_stack *b);
void			get_visual(t_data *data);
int				find_max(t_stack *stack);
int				press_key(int key, t_data *data);
int				run_visual(t_data *data);
void			fill_background(t_data *data);
void			draw_stack(t_data *data);
void			draw_line(t_data *data, int line_h, int start_y, int start_x);
void			put_pxl(t_data *data, int x, int y, int color);
unsigned int	*get_texls(t_image *texture, int x, int y);

void			swap_top(t_stack *stack);
void			push_top(t_stack *a, t_stack *b);
void			rotate_stack(t_stack *stack);
void			reverse_rotate_stack(t_stack *stack);

#endif
