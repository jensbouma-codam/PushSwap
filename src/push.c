/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:12:50 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/08 18:53:04 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param t_stacks s 
 * @return int 
 */
int	push_ba(t_stacks *s)
{
	t_stack	*next;

	write(1, "pa\n", 3);
	if (!s->b)
		return (false);
	if (!s->a)
		next = NULL;
	else
		next = s->a;
	s->b->prev = NULL;
	s->a = s->b;
	s->b = s->b->next;
	s->a->next = next;
	s->last_a = stack_last(s->a);
	return (true);
}

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param t_stacks s  
 * @return int 
 */
int	push_ab(t_stacks *s)
{
	t_stack	*next;

	write(1, "pb\n", 3);
	if (!s->a)
		return (false);
	if (!s->b)
		next = NULL;
	else
		next = s->b;
	s->b = s->a;
	s->a = s->a->next;
	s->a->prev = NULL;
	s->b->next = next;
	if (s->b->next)
		s->b->next->prev = s->b;
	s->last_b = stack_last(s->b);
	return (true);
}
