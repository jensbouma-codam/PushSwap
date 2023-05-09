/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:12:50 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 10:38:23 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b, t_stack **last_a, t_stack **last_b)
{
	t_stack	*next;

	if (!(*b))
	{
		next = NULL;
		*last_b = *a;
	}
	else
		next = *b;
	if (!(*a)->next)
		*last_a = NULL;
	*b = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	(*b)->next = next;
	if ((*b)->next)
		(*b)->next->prev = *b;
}


/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param t_stacks s 
 * @return int 
 */
int	push_ba(t_stacks *s)
{
	write(1, "pb\n", 3);
	if (!s->b)
		return (false);
	push(&s->b, &s->a, &s->last_b, &s->last_a);
	s->size_b--;
	s->size_a++;
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
	write(1, "pb\n", 3);
	if (!s->a)
		return (false);
	push(&s->a, &s->b, &s->last_a, &s->last_b);
	s->size_a--;
	s->size_b++;
	return (true);
}



// /**
//  * @brief Take the first element at the top of b and put it at the top of a.
//  * Do nothing if b is empty.
//  * 
//  * @param t_stacks s 
//  * @return int 
//  */
// int	push_ba(t_stacks *s)
// {
// 	t_stack	*next;

// 	write(1, "pa\n", 3);
// 	if (!s->b)
// 		return (false);
// 	if (!s->a)
// 		next = NULL;
// 	else
// 		next = s->a;
// 	s->a = s->b;
// 	s->b = s->b->next;
// 	if (s->b)
// 		s->b->prev = NULL;
// 	s->a->next = next;
// 	if (s->a->next)
// 		s->a->next->prev = s->a;
// 	s->last_a = stack_last(s->a);
// 	return (true);
// }