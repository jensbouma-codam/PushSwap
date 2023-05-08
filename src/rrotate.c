/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrotate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 16:05:45 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/08 18:29:44 by jbouma        ########   odam.nl         */
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
	// t_stack	*first;
	// t_stack	*last;

	if (!s->a)
		return (false);
	write(1, "rra\n", 4);
	s->a = reverse_rotate(s->a, s->last_a);
	s->last_a = stack_last(s->a);
	s->size_a = stack_size(s->a);
	// first = s->a;
	// last = s->last_a;
	// if (!s->a->next)
	// 	return (false);
	// s->last_a->prev->next = NULL;
	// s->a = s->last_a;
	// s->a->next = first;
	// first->prev = s->a;
	// s->last_a = last->prev;
	ft_printf("Last a: %d\n", s->last_a->value);
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
	t_stack	*first;
	t_stack	*last;
	if (!s->b)
		return (false);
	first = s->b;
	last = s->last_b;
	write(1, "rrb\n", 4);
	if (!s->b->next)
		return (false);
	s->last_b->prev->next = NULL;
	s->b = s->last_b;
	s->b->next = first;
	first->prev = s->b;
	s->last_b = last->prev;
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
	t_stack	*first;
	t_stack	*last;

	first = s->a;
	last = s->last_a;
	write(1, "rrr\n", 4);
	if (!s->a->next)
		return (false);
	s->last_a->prev->next = NULL;
	s->a = s->last_a;
	s->a->next = first;
	first->prev = s->a;
	s->last_a = last->prev;
	first = s->b;
	last = s->last_b;
	if (!s->b->next)
		return (false);
	s->last_b->prev->next = NULL;
	s->b = s->last_b;
	s->b->next = first;
	first->prev = s->b;
	s->last_b = last->prev;
	return (true);
}
