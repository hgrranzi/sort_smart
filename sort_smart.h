/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef SORT_SMART_H
# define SORT_SMART_H

# include "checker.h"

typedef struct	s_info
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*cmd;
	char		**commands;
}				t_info;

void	sort_stupid(t_info *data);
int		find_min(t_stack *stack);

#endif
