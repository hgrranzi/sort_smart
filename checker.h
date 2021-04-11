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

int		aka_atoi(char *str);
int		aka_isdigit(char c);

#endif
