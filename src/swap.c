/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:57:49 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/28 18:54:24 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @briefSwap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	sa(t_stack *stack)
{
	int	tmp;

	write(1, "sa\n", 3);
	if (!stack->next)
		return (false);
	tmp = stack->next->value;
	stack->next->value = stack->value;
	stack->value = tmp;
	return (true);
}

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	sb(t_stack *stack)
{
	int	tmp;

	write(1, "sb\n", 3);
	if (!stack->next)
		return (false);
	tmp = stack->next->value;
	stack->next->value = stack->value;
	stack->value = tmp;
	return (true);
}

/**
 * @brief sa and sb at the same time.
 * 
 * @return int 
 */
int	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	write(1, "ss\n", 3);
	if (!a->next)
		return (false);
	tmp = a->next->value;
	a->next->value = a->value;
	a->value = tmp;
	if (!b->next)
		return (false);
	tmp = b->next->value;
	b->next->value = b->value;
	b->value = tmp;
	return (true);
}

// 
// ra (rotate a): Shift up all elements of stack a by 1. 
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.
