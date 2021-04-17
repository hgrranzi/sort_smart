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
# define SPEED_DELAY 10
# define WIN_W 1280
# define PADDING 10
# define IMG_PATH "pic/red_space.xpm"

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
	float		stripe_w;
	float		stripe_h;
	void		*mlx_p;
	void		*win_p;
	t_image		*back;
	t_image		*visual;

}				t_data;


void	checker(t_stack *a, t_stack *b);
void	exec_cmd(char *line, t_stack *a, t_stack *b);

void	get_visual(t_data *data);
void	fill_background(t_data *data);
int		run_visual(t_data *data);

void	swap_top(t_stack *stack);
void	push_top(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif
