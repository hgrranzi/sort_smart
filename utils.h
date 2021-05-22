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
void	aka_putstr(char *s);
size_t	aka_strlen(const char *s);
int		aka_strcmp(const char *s1, const char *s2);
char	*aka_strdup(const char *s);
void	create_stacks(char **argv, int i, t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
int		find_max(t_stack *stack);
int		find_index_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_index_min(t_stack *stack);

#endif
