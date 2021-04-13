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
# include "stack.h"

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

void	checker(t_stack *a, t_stack *b);
void	exec_cmd(char *line, t_stack *a, t_stack *b);

void	swap_top(t_stack *stack);
void	push_top(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

void	display_error();

int		aka_atoi(char *str);
int		aka_isdigit(char c);
void	aka_putchar(char c);
void	aka_putnbr(int nbr);
void	print_stack(t_stack *stack);

#endif
