/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:57:49 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/08 16:05:37 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	swap_a(t_stacks *s)
{
	int	tmp;

	write(1, "sa\n", 3);
	if (!s->a->next)
		return (false);
	tmp = s->a->next->value;
	s->a->next->value = s->a->value;
	s->a->value = tmp;
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
	int	tmp;

	write(1, "sb\n", 3);
	if (!s->b->next)
		return (false);
	tmp = s->b->next->value;
	s->b->next->value = s->b->value;
	s->b->value = tmp;
	return (true);
}

/**
 * @brief sa and sb at the same time.
 * 
 * @return int 
 */
int	swap_both(t_stacks *s)
{
	int	tmp;

	write(1, "ss\n", 3);
	if (!s->a->next)
		return (false);
	tmp = s->a->next->value;
	s->a->next->value = s->a->value;
	s->a->value = tmp;
	if (!s->b->next)
		return (false);
	tmp = s->b->next->value;
	s->b->next->value = s->b->value;
	s->b->value = tmp;
	return (true);
}
