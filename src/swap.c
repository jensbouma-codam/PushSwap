/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:57:49 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 11:14:48 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack, t_stack **last)
{
	t_stack	*next;

	if (!(*stack) || !(*stack)->next)
		return ;
	if ((*last) == (*stack)->next)
		(*last) = (*stack);
	next = (*stack)->next;
	(*stack)->next = next->next;
	next->next = *stack;
	next->next->prev = next;
	(*stack) = next;
	(*stack)->prev = NULL;
}

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	swap_a(t_stacks *s)
{
	write(1, "sa\n", 3);
	swap(&s->a, &s->last_a);
	return (true);
}


/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	swap_b(t_stacks *s)
{
	write(1, "sb\n", 3);
	swap(&s->b, &s->last_b);
	return (true);
}

/**
 * @brief sa and sb at the same time.
 * 
 * @return int 
 */
int	swap_both(t_stacks *s)
{
	write(1, "ss\n", 3);
	swap(&s->a, &s->last_a);
	swap(&s->b, &s->last_b);
	return (true);
}

// int	swap_a(t_stacks *s)
// {
// 	// t_stack	*next;

// 	write(1, "sa\n", 3);
// 	if (!s->a || !s->a->next)
// 		return (false);
// 	swap(&s->a, &s->last_a);
// 	// if (s->last_a == s->a->next)
// 	// 	s->last_a = s->a;
// 	// next = s->a->next;
// 	// s->a->next = next->next;
// 	// next->next = s->a;
// 	// next->next->prev = next;
// 	// s->a = next;
// 	// s->a->prev = NULL;
// 	return (true);
// }