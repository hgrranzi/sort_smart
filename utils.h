/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "stack.h"

int		aka_atoi(char *str);
int		aka_isdigit(char c);
void	aka_putchar(char c);
void	aka_putnbr(int nbr);
void	create_stacks(char **argv, int i, t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
void	display_error();

#endif
