/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:41:01 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/17 16:11:21 by jbouma        ########   odam.nl         */
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
		if ((int)(calc * 10 + (*str - '0')) == INT_MIN)
			return (INT_MIN);
		if (calc * 10 + (*str - '0') > INT_MAX)
			exit_error("Value outside range of INT_MAX");
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
			exit_error("Double value detected");
		stack = stack->next;
	}
}

void	handle_arguments(t_stacks **s, int argc, char **argv)
{
	int		stack_length;
	int		i;
	int		n;

	if (argc <= 1)
		exit_error("No arguments given");
	(*s)->a = NULL;
	stack_length = 0;
	while (stack_length < argc - 1)
	{
		stack_length++;
		i = 0;
		while (argv[stack_length][i])
			if (!ft_isdigit(argv[stack_length][i++]))
				if (!(argv[stack_length][0] == '-'
					&& ft_isdigit(argv[stack_length][i])))
					exit_error("Value isn't a number");
		if (argv[stack_length][0] == 0)
			exit_error("Empty value");
		n = ft_atoi_protect_maxint(argv[stack_length]);
		check_duplicates((*s)->a, n);
		(*s)->a = add((*s)->a, n);
		++(*s)->len_stack_a;
	}
	(*s)->last_a = stack_last((*s)->a);
}

// What if there are multiple '-'? 
// What if 2nd number 
//leading 0000???  
// Doe eens een string handlene ook!
//  1 2 3 4 5 0 ->>> WTF is er met 0?
