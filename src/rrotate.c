/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrotate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 16:05:45 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/15 14:51:22 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack, t_stack **last)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	(*last)->prev->next = NULL;
	*stack = *last;
	(*stack)->next = first;
	first->prev = *stack;
	*last = (*last)->prev;
	(*stack)->prev = NULL;
}

/**
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * 
 * @param s 
 */
void	rrotate_a(t_stacks *s)
{
	write(1, "rra\n", 4);
	reverse_rotate(&s->a, &s->last_a);
}

/**
 * @brief rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * 
 * @param s 
 */
void	rrotate_b(t_stacks *s)
{
	write(1, "rrb\n", 4);
	reverse_rotate(&s->b, &s->last_b);
}

/**
 * @brief rra and rrb at the same time.
 * 
 * @param s 
 */
void	rrotate_both(t_stacks *s)
{
	write(1, "rrr\n", 4);
	reverse_rotate(&s->a, &s->last_a);
	reverse_rotate(&s->b, &s->last_b);
}
