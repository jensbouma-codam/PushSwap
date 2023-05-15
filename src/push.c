/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:12:50 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/15 16:34:39 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_stack **f, t_stack **t, t_stack **last_f, t_stack **last_t)
{
	t_stack	*next;

	if (!(*f))
		return (false);
	if (!(*t))
	{
		next = NULL;
		*last_t = *f;
	}
	else
		next = *t;
	if (!(*f)->next)
		*last_f = NULL;
	*t = *f;
	*f = (*f)->next;
	if (*f)
		(*f)->prev = NULL;
	(*t)->next = next;
	if ((*t)->next)
		(*t)->next->prev = *t;
	return (true);
}

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param t_stacks s 
 */
void	push_ab(t_stacks *s)
{
	write(1, "pb\n", 3);
	if (push(&s->a, &s->b, &s->last_a, &s->last_b))
	{
		s->len_stack_a--;
		s->len_stack_b++;
	}
}

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param t_stacks s 
 */
void	push_ba(t_stacks *s)
{
	write(1, "pa\n", 3);
	if (push(&s->b, &s->a, &s->last_b, &s->last_a))
	{
		s->len_stack_b--;
		s->len_stack_a++;
	}
}
