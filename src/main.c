/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/28 17:52:26 by jensbouma     ########   odam.nl         */
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

t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack	*stack = NULL;
	int		stack_length;
	int		i;
	int		n;

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
		if (!stack)
			stack = ft_int_lstnew(n);
		else
			ft_int_lstadd_back(stack, ft_int_lstnew(n));
	}
	return (stack);
}

// Check for duplicates!!!
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = initialize_stack(argc, argv);
		ft_printf("Stack A\t\t StackB\n%i\t\t%i\n",
			ft_int_lstsize(stack_a), ft_int_lstsize(stack_b));
		while (stack_a || stack_b)
		{
			if (stack_a)
			{
				ft_printf("%i\t\t", stack_a->value);
				stack_a = stack_a->next;
			}
			else
				ft_printf("----\t\t");
			if (stack_b)
			{
				ft_printf("%i\n", stack_b->value);
				stack_b = stack_b->next;
			}
			else
				ft_printf("----\n");
		}
		return (EXIT_SUCCESS);
	}
	error_exit("No arguments given");
}
