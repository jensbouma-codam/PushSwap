/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/08 11:24:18 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

int	ft_atoi_protect_maxint(char *str)
{
	int				min;
	unsigned long	calc;

	min = 1;
	calc = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = -min;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (calc * 10 + (*str - '0') > INT_MAX)
			error_exit("Value outside range of INT_MAX");
		calc = calc * 10 + (*str - '0');
		str++;
	}
	return (calc * min);
}

t_stack	*add2top(t_stack *stack, int value)
{
	t_stack	*node;

	node = (t_stack *)safe_calloc(1, sizeof(*node));
	if (!node)
		error_exit("Memory allocation failed");
	node->value = value;
	if (stack)
		node->next = stack;
	return (node);
}

t_stack	*add(t_stack *stack, int value)
{
	t_stack			*node;
	t_stack			*last;

	node = (t_stack *)safe_calloc(1, sizeof(*node));
	if (!node)
		error_exit("Memory allocation failed");
	node->value = value;
	node->next = 0;
	if (!stack)
		return (node);
	last = stack;
	while (last->next)
		last = last->next;
	last->next = node;
	return (stack);
}

void	check_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (value == stack->value)
			error_exit("Double value detected");
		stack = stack->next;
	}
}


t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		stack_length;
	int		i;
	int		n;

	stack = NULL;
	stack_length = 0;
	while (stack_length < argc - 1)
	{
		stack_length++;
		i = 0;
		while (argv[stack_length][i])
			if (!ft_isdigit(argv[stack_length][i++]))
				if (!(argv[stack_length][0] == '-'
					&& ft_isdigit(argv[stack_length][i])))
					error_exit("Value isn't a number");
		if (argv[stack_length][0] == 0)
			error_exit("Empty value");
		n = ft_atoi_protect_maxint(argv[stack_length]);
		check_duplicates(stack, n);
		stack = add(stack, n);
	}
	return (stack);
}


// Check for duplicates!!!
int	main(int argc, char **argv)
{
	t_stacks	*s;

	s->a = NULL;
	s->b = NULL;

	if (argc > 1)
	{
		s->a = initialize_stack(argc, argv);
		s->b = add2top(s->b, 100);
		for (size_t i = 0; i < 10; i++)
			s->b = add2top(s->b, random()/10000000 + 100);
			// ft_int_lstadd_back(stack_b, ft_int_lstnew(i + 101));		
		// sa(stack_a);
		// sb(stack_b);
		// pa(stack_a, stack_b);
		// ss(stack_a, stack_b);
		// stack_b = pb(stack_a, stack_b);
		// stack_b = pb(stack_a, stack_b);
		// stack_b = pb(stack_a, stack_b);
		// pb(stack_a, stack_b);
		debug(s->a, s->b);
		return (EXIT_SUCCESS);
	}
	error_exit("No arguments given");
}
