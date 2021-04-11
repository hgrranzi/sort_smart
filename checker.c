/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void	display_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		display_error();
	write(1, "Checker works\n", 14);
	return (0);
}
