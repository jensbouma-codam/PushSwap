/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 16:05:45 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/08 19:24:58 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * 
 * @param s 
 * @return int 
 */
int	rotate_a(t_stacks *s)
{
	write(1, "ra\n", 3);
	if (!s->a->next)
		return (false);
	s->last_a->next = s->a;
	s->a = s->a->next;
	s->a->prev = NULL;
	s->a->next->prev = s->a;
	s->last_a->next->next = NULL;
	s->last_a = s->last_a->next;
	return (true);
}


/**
 * @brief rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * 
 * @param s 
 * @return int 
 */
int	rotate_b(t_stacks *s)
{
	write(1, "rb\n", 3);
	if (!s->b->next)
		return (false);
	s->last_b->next = s->b;
	s->b = s->b->next;
	s->b->prev = NULL;
	s->b->next->prev = s->b;
	s->last_b->next->next = NULL;
	s->last_b = s->last_b->next;
	return (true);
}

/**
 * @brief ra and rb at the same time.
 * 
 * @param s 
 * @return int 
 */
int	rotate_both(t_stacks *s)
{
	write(1, "rr\n", 3);
	if (!s->a->next)
		return (false);
	s->last_a->next = s->a;
	s->a = s->a->next;
	s->a->prev = NULL;
	s->last_a->next->next = NULL;
	s->last_a = s->last_a->next;
	if (!s->b->next)
		return (false);
	s->last_b->next = s->b;
	s->b = s->b->next;
	s->b->prev = NULL;
	s->last_b->next->next = NULL;
	s->last_b = s->last_b->next;
	return (true);
}
