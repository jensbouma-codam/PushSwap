/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:41:01 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/08 15:17:45 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_protect_maxint(char *str)
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

static void	check_duplicates(t_stack *stack, int value)
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
