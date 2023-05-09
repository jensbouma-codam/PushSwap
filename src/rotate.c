/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 16:05:45 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/09 11:13:06 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	rotate(t_stack **stack, t_stack **last)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*last)->next = first;
	first->prev = *last;
	first->next = NULL;
	*last = first;
}

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
	rotate(&s->a, &s->last_a);
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
	rotate(&s->b, &s->last_b);
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
	rotate(&s->a, &s->last_a);
	rotate(&s->b, &s->last_b);
	return (true);
}


// /**
//  * @brief ra (rotate a): Shift up all elements of stack a by 1.
//  * The first element becomes the last one.
//  * 
//  * @param s 
//  * @return int 
//  */
// int	rotate_a(t_stacks *s)
// {
// 	write(1, "ra\n", 3);
// 	if (!s->a || !s->a->next)
// 		return (false);
// 	rotate(&s->a, &s->last_a);
// 	return (true);

// 	// s->last_a->next = s->a;
// 	// s->last_a->next->prev = s->last_a;
// 	// s->a = s->a->next;
// 	// s->a->prev = NULL;
// 	// s->a->next->prev = s->a;
// 	// s->last_a->next->next = NULL;
// 	// s->last_a = s->last_a->next;
// 	return (true);
// }
