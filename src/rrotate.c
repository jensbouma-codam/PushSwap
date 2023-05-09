/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrotate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 16:05:45 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/09 10:46:06 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static t_stack	*reverse_rotate(t_stack *stack, t_stack *last)
{
	t_stack	*first;

	first = stack;
	last->prev->next = NULL;
	stack = last;
	stack->next = first;
	first->prev = stack;
	last = last->prev;
	stack->prev = NULL;
	return (stack);
}

/**
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * 
 * @param s 
 * @return int 
 */
int	rrotate_a(t_stacks *s)
{
	write(1, "rra\n", 4);
	if (!s->a || !s->a->next)
		return (false);
	s->a = reverse_rotate(s->a, s->last_a);
	s->last_a = stack_last(s->a);
	s->size_a = stack_size(s->a);
	return (true);
}


/**
 * @brief rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * 
 * @param s 
 * @return int 
 */
int	rrotate_b(t_stacks *s)
{
	write(1, "rrb\n", 4);
	if (!s->b || !s->b->next)
		return (false);
	s->b = reverse_rotate(s->b, s->last_b);
	s->last_b = stack_last(s->b);
	s->size_b = stack_size(s->b);
	return (true);
}

/**
 * @brief rra and rrb at the same time.
 * 
 * @param s 
 * @return int 
 */
int	rrotate_both(t_stacks *s)
{
	write(1, "rrr\n", 4);
	if (!s->a || !s->a->next)
		return (false);
	s->a = reverse_rotate(s->a, s->last_a);
	s->last_a = stack_last(s->a);
	s->size_a = stack_size(s->a);
	if (!s->b || !s->b->next)
		return (false);
	s->b = reverse_rotate(s->b, s->last_b);
	s->last_b = stack_last(s->b);
	s->size_b = stack_size(s->b);
	return (true);
}
