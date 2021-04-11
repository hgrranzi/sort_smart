/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_stack
{
	int			*data;
	int			status;
	int			size;
}				t_stack;

void	display_error();
void	checker(t_stack *a, t_stack *b);

int		*init_stack(t_stack *stack, int size);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
void	push(t_stack *stack, int element);
int		pop(t_stack *stack);
void	destroy_stack(t_stack *stack);
void	print_stack(t_stack *stack);

int		aka_atoi(char *str);
int		aka_isdigit(char c);
void	aka_putchar(char c);
void	aka_putnbr(int nbr);

#endif
