/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

void		display_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

int			is_duplicate(int nbr, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->status)
	{
		if (stack->data[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int			is_sorted(t_stack *stack)
{
	int		i;

	i = stack->status - 1;
	while (i > 0)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void		exec_cmd(t_stack *a, t_stack *b, int command)
{
	return ;
}

int			check_cmd(char *line)
{
	if (strcmp(line, "sa") == 0)
		return (SA);
	if (strcmp(line, "sb") == 0)
		return (SB);
	if (strcmp(line, "ss") == 0)
		return (SS);
	if (strcmp(line, "pa") == 0)
		return (PA);
	if (strcmp(line, "pb") == 0)
		return (PB);
	if (strcmp(line, "ra") == 0)
		return (RA);
	if (strcmp(line, "rb") == 0)
		return (RB);
	if (strcmp(line, "rr") == 0)
		return (RR);
	if (strcmp(line, "rra") == 0)
		return (RRA);
	if (strcmp(line, "rrb") == 0)
		return (RRB);
	if (strcmp(line, "rrr") == 0)
		return (RRR);
	return (0);
}

void		swap_a(t_stack *a, t_stack *b)
{
	write(1, "sa ok\n", 6);
}

void		swap_b(t_stack *a, t_stack *b)
{
	write(1, "sb ok\n", 6);
}

void		sa_sb(t_stack *a, t_stack *b)
{
	write(1, "ss ok\n", 6);
}

void		push_a(t_stack *a, t_stack *b)
{
	write(1, "pa ok\n", 6);
}

void		push_b(t_stack *a, t_stack *b)
{
	write(1, "pb ok\n", 6);
}

void		rotate_a(t_stack *a, t_stack *b)
{
	write(1, "ra ok\n", 6);
}

void		rotate_b(t_stack *a, t_stack *b)
{
	write(1, "rb ok\n", 6);
}

void		ra_rb(t_stack *a, t_stack *b)
{
	write(1, "rr ok\n", 6);
}

void		reverse_rotate_a(t_stack *a, t_stack *b)
{
	write(1, "rra ok\n", 7);
}

void		reverse_rotate_b(t_stack *a, t_stack *b)
{
	write(1, "rrb ok\n", 7);
}

void		rra_rrb(t_stack *a, t_stack *b)
{
	write(1, "rrr ok\n", 7);
}

void		checker(t_stack *a, t_stack *b)
{
	int		readed;
	char	*line;
	int		cmd;
	void	(*exec[CMD_NUMBER + 1])(t_stack *, t_stack *);

	exec[NOT_CMD] = &display_error;
	exec[SA] = &swap_a;
	exec[SB] = &swap_b;
	exec[SS] = &sa_sb;
	exec[PA] = &push_a;
	exec[PB] = &push_b;
	exec[RA] = &rotate_a;
	exec[RB] = &rotate_b;
	exec[RR] = &ra_rb;
	exec[RRA] = &reverse_rotate_a;
	exec[RRB] = &reverse_rotate_b;
	exec[RRR] = &rra_rrb;
	while (get_next_line(0, &line))
	{
		cmd = check_cmd(line);
		exec[cmd](a, b);
	}
	if (is_empty(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int			main(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_stack	a;
	t_stack	b;

	i = argc - 1;
	if (argc > 1)
	{
		if (!(init_stack(&a, argc - 1)) || (!init_stack(&b, argc - 1)))
			display_error();
		while (i > 0)
		{
			nbr = aka_atoi(argv[i]);
			if (is_duplicate(nbr, &a))
				display_error();
			push(&a, nbr);
			i--;
		}
		checker(&a, &b);
		print_stack(&a);
	}
	return (0);
}
