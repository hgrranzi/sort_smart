/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "utils.h"
#include <stdio.h>

int	aka_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	aka_atoi(char *str) // need to add max and min int
{
	long	nbr;
	long	sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		&& aka_isdigit(str[i + 1]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && aka_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && aka_isdigit(str[i]) && nbr <= INT_MAX)
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || nbr * sign > INT_MAX || nbr * sign < -INT_MAX - 1)
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

int	aka_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	create_stacks(char **argv, int i, t_stack *a, t_stack *b)
{
	int	nbr;

	if (!(init_stack(a, i - 1)) || (!init_stack(b, i - 1)))
		display_error();
	while (i > 0)
	{
		nbr = aka_atoi(argv[i]);
		if (is_duplicate(nbr, a))
			display_error();
		push(a, nbr);
		i--;
	}
}

void	print_stack(t_stack *stack)
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
