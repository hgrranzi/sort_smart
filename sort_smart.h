/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef SORT_SMART_H
# define SORT_SMART_H

# include "checker.h"

# define DIVISER 50

typedef struct s_moves
{
	int			a;
	int			b;
}				t_moves;

typedef struct s_info
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*cmd;
	char		**commands;
	int			flag;
}				t_info;

char	**init_commands(char **commands, int size);
void	print_commands(t_stack *stack, char **commands);
void	destroy_commands(char **commands, int size);

void	sort_stack(t_info *info, int stack_size);
void	check_sort(t_info *info, int stack_size, t_stack *cmd_min, t_stack *a_copy);
void	sort_smart(t_info *info, int stack_size);
void	end_sort(t_info *info);

void	sort_clever(t_info *info);
void	sort_few(t_info *info);
void	sort_more(t_info *info);

int		*copy_stack_data(t_stack *stack);
void	copy_stack(t_stack *dst, t_stack *src);
void	sort_array(int	*array, int size);
void	index_stack(t_stack *stack);

t_stack	*best_sequence(t_stack *stack);
int		check_sequence(int *data, int *len, int size);
int		index_len_max(int *len, int size);
int		*make_sequence(int *len, int *data, int len_size, int index_max);

void	move_unsorted(t_info *info, t_stack *sorted);
int		is_in_sequence(t_stack *sorted, int num);

void	move_bestone(t_info *info);
void	find_bestone(t_stack *a, t_stack *b, t_moves *bestone);
int		right_place(t_stack *stack, int num);

int		count_moves(int b_moves, int a_moves);
void	check_moves(t_stack *a, t_stack *b, t_moves index, t_moves *moves);
int		max(int a, int b);
int		positive(int num);
void	rotate_it(t_info *info);
void	exec_rotate(t_info *info, t_moves *bestone);
void	exec_reverse_rotate(t_info *info, t_moves *bestone);

void	move_bestone_b(t_info *info, t_stack *sorted);
void	find_bestone_b(t_stack *a, t_stack *b, t_moves *bestone, t_stack *sorted);
int		right_place_b(t_stack *stack, int num);

#endif
