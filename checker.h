/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <string.h>
#include <math.h>
# include "mlx/mlx.h"
# include "get_next_line.h"
# include "utils.h"

# define CMD_NUMBER 11
# define NOT_CMD 0
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define SPEED_DELAY 10000
# define WIN_W 1280
# define PADDING 10
# define IMG_PATH "pic/red_space.xpm"
# define HISTORY_SIZE 10

typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line;
	int				endian;
	int				w;
	int				h;
}					t_image;

typedef struct	s_data
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*history;
	float		stripe_w;
	float		stripe_h;
	void		*mlx_p;
	void		*win_p;
	t_image		*back;
	t_image		*visual;
	int			play;
	id_t		pause;
	int			speed_delay;

}				t_data;


void			checker(t_stack *a, t_stack *b);
void			exec_cmd(char *line, t_stack *a, t_stack *b);

void			get_visual(t_data *data);
int				find_max(t_stack *stack);
int				press_key(int key, t_data *data);
int				run_visual(t_data *data);
void			fill_background(t_data *data);
void			draw_stack(t_data *data);
void			draw_stripe(t_data *data, int stripe_h, int start_y, int start_x);
void			put_pxl(t_data *data, int x, int y, int color);
unsigned int	*get_texls(t_image *texture, int x, int y);

void			swap_top(t_stack *stack);
void			push_top(t_stack *a, t_stack *b);
void			rotate_stack(t_stack *stack);
void			reverse_rotate_stack(t_stack *stack);

#endif
