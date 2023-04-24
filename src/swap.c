/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:57:49 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/24 19:01:44 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @briefSwap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	sa(void)
{
	write(1, "sa\n", 3);
	return (true);
}

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * 
 * @return int 
 */
int	sb(void)
{
	write(1, "sb\n", 3);
	return (true);
}

/**
 * @brief sa and sb at the same time.
 * 
 * @return int 
 */
int	ss(void)
{
	write(1, "ss\n", 3);
	return (true);
}



// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.

// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.
