/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 12:04:50 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/09 11:29:03 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		len;

	len = 0;
	while (stack && ++len)
		stack = stack->next;
	return (len);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*add(t_stack *stack, int value)
{
	t_stack			*node;

	node = (t_stack *)safe_calloc(1, sizeof(*node));
	if (!node)
		exit_error("Memory allocation failed");
	node->value = value;
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

// t_stack	*addtop(t_stack *stack, int value)
// {
// 	t_stack	*node;

// 	node = (t_stack *)safe_calloc(1, sizeof(*node));
// 	if (!node)
// 		exit_error("Memory allocation failed");
// 	node->value = value;
// 	if (stack)
// 		node->next = stack;
// 	return (node);
// }
