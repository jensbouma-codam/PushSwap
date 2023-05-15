/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 09:35:31 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/15 17:55:43 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_int_length(int n)
{
	int	i;

	i = 0;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	bit_value(long n, int x)
{
	if ((n >> x) & 1)
		return (1);
	return (0);
}

bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	if (DEBUG)
		ft_printf("Stack is sorted\n");
	return (true);
}

bool	is_rev_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			return (false);
		stack = stack->next;
	}
	if (DEBUG)
		ft_printf("Stack is rev sorted\n");
	return (true);
}
