/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>

# define PLUS_SIZE 32

typedef struct	s_stack
{
	int			*data;
	int			status;
	int			size;
}				t_stack;

int		*init_stack(t_stack *stack, int size);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
int		is_duplicate(int nbr, t_stack *stack);
int		is_sorted(t_stack *stack);
void	push(t_stack *stack, int element);
int		pop(t_stack *stack);
void	destroy_stack(t_stack *stack);

void	display_error(void);

#endif
