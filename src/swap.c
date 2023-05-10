/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:57:49 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/10 12:09:33 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack, t_stack **last)
{
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	if ((*last) == (*stack)->next)
		(*last) = (*stack);
	first = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = (*stack)->next;
	if (first->next)
		first->next->prev = first;
	(*stack)->next = first;
	(*stack)->next->prev = (*stack);
}

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 */
void	swap_a(t_stacks *s)
{
	write(1, "sa\n", 3);
	swap(&s->a, &s->last_a);
}

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 */
void	swap_b(t_stacks *s)
{
	write(1, "sb\n", 3);
	swap(&s->b, &s->last_b);
}

/**
 * @brief sa and sb at the same time.
 */
void	swap_both(t_stacks *s)
{
	write(1, "ss\n", 3);
	swap(&s->a, &s->last_a);
	swap(&s->b, &s->last_b);
}
