/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef SORT_SMART_H
# define SORT_SMART_H

# include "checker.h"

typedef struct s_moves
{
	int			a;
	int			b;
}				t_moves;

typedef struct	s_info
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*cmd;
	char		**commands;
}				t_info;

char			**init_commands(char **commands, int size);
void			print_commands(t_stack *stack, char **commands);

void			sort_stupid(t_info *data);

void			sort_clever(t_info *info);
void			sort_few(t_info *info);
void			sort_more(t_info *info);

int				*copy_stack_data(t_stack *stack);
void			sort_array(int	*array, int size);
void			index_stack(t_stack *stack);

t_stack			*best_sequence(t_stack *stack);
int				check_sequence(int *data, int *len, int size);
int				index_len_max(int *len, int size);
int				*make_sequence(int *len, int *data, int len_size, int index_max);

void			move_unsorted(t_info *info, t_stack *sorted);
int				is_in_sequence(t_stack *sorted, int num);
void			check_swaps(t_info *info, t_stack *sorted);
void			check_push(t_info *info, t_stack *sorted);

void			move_bestone(t_info *info);
void			find_bestone(t_stack *a, t_stack *b, t_moves *bestone);
int				right_place(t_stack *stack, int num);
int				count_moves(int b_moves, int a_moves);
void			check_moves(t_stack *a, t_stack *b, t_moves index, t_moves *moves);
int				max(int a, int b);
int				positive(int num);
void			rotate_it(t_info *info);
void			exec_rotate(t_info *info, t_moves *bestone);
void			exec_reverse_rotate(t_info *info, t_moves *bestone);



#endif
