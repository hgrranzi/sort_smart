/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef SORT_SMART_H
# define SORT_SMART_H

# include "checker.h"

typedef struct	s_sorted
{
	int			*sequence;
	int			size;
}				*t_sorted;

typedef struct	s_info
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*cmd;
	char		**commands;
}				t_info;

char	**init_commands(char **commands, int size);

void	sort_stupid(t_info *data);
int		find_min(t_stack *stack);

void	sort_clever(t_info *info);
int		*copy_stack_data(t_stack *stack);
void	sort_array(int	*array, int size);
void	index_stack(t_stack *stack);
void	best_sequence(t_info *info);
void	check_sequence(int *data, int *len, int size);
int		index_len_max(int *len, int size);
int		*make_sequence(int *len, int *data, int len_size, int index_max);




#endif
