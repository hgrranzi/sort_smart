/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"

# define INT_MAX 2147483647

int		aka_atoi(char *str);
int		aka_isdigit(char c);
void	aka_putchar(char c);
void	aka_putnbr(int nbr);
int		aka_strcmp(const char *s1, const char *s2);
void	create_stacks(char **argv, int i, t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min_min(t_stack *stack);

#endif
