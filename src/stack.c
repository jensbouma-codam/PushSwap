/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 12:04:50 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/19 17:14:00 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_stack_max(t_stack *stack)
{
	unsigned int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

unsigned int	get_stack_min(t_stack *stack)
{
	unsigned int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	add_index(t_stack *s)
{
	const int	min = get_stack_min(s);

	while (s)
	{
		s->index = s->value - min;
		s = s->next;
	}
}

t_stack	*add(t_stack *stack, long value)
{
	t_stack			*node;

	node = (t_stack *)safe_calloc(1, sizeof(*node));
	if (!node)
		exit_error("Memory allocation failed");
	node->value = value;
	node->length = get_int_length(value);
	node->next = 0;
	if (!stack)
	{
		node->prev = NULL;
		return (node);
	}
	node->prev = stack_last(stack);
	stack_last(stack)->next = node;
	return (stack);
}
