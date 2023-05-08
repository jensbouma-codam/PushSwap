/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:12:50 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/01 21:21:52 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int	pa(t_stack *a, t_stack *b)
{
	int	tmp;

	write(1, "pa\n", 3);
	if (!b)
		return (false);
	tmp = b->value;
	b->value = a->value;
	a->value = tmp;
	return (true);
}

t_stack	*ft_int_delone(t_stack *lst)
{
	free(lst->value);
	lst = lst->next;
	lst->value = lst->next->value;
	return (lst);
}

/**
 * 
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
t_stack	*pb(t_stack *a, t_stack *b)
{
	write(1, "pb\n", 3);

	if (!a)
		return (false);
	if (b)
	{
		// a = ft_int_delone(a);
		return (ft_int_lstadd_front(b, ft_int_lstnew(a->value)));
	}
	return (ft_int_lstnew(a->value));
}
