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
	int	i;

	i = 1;
	if (argc > 1)
	{
		write(1, "Checker works\n", 14);
		while (i < argc)
		{
			printf("%d\n", aka_atoi(argv[i]));
			i++;
		}
	}
	return (0);
}
