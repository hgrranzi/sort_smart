/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

int		aka_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		aka_atoi(char *str) // need to add max and min int
{
	long	nbr;
	long	sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (aka_isdigit(str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		display_error();
	return ((int)(nbr * sign));
}

void	aka_putchar(char c)
{
	write(1, &c, 1);
}

void	aka_putnbr(int nbr)
{
	if (nbr < 0)
	{
		aka_putchar('-');
		aka_putnbr(-1 * nbr);
	}
	else
	{
		if (nbr > 9)
			aka_putnbr(nbr / 10);
		aka_putchar(nbr % 10 + 48);
	}
}

void	print_stack(t_stack *stack) // probably will be better with my own printf
{
	int	i;

	i = stack->status - 1;
	write(1, "---\n", 4);
	while (i >= 0)
	{
		aka_putchar('|');
		aka_putnbr(stack->data[i]);
		aka_putchar('|');
		aka_putchar('\n');
		i--;
	}
	write(1, "---\n", 4);
}
