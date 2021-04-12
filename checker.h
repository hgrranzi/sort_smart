/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <string.h>
# include "get_next_line.h"

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

typedef struct	s_stack
{
	int			*data;
	int			status;
	int			size;
}				t_stack;

void	checker(t_stack *a, t_stack *b);
int		check_cmd(char *line);
void	exec_cmd(t_stack *a, t_stack *b, int command);

void	display_error();
int		is_duplicate(int nbr, t_stack *stack);
int		is_sorted(t_stack *stack);

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
