/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 23:14:57 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/25 00:07:46 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_int_lstnew(int value)
{
	t_stack	*node;

	node = (t_stack *)ft_calloc(1, sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->next = 0;
	return (node);
}

t_stack	*ft_int_lstlast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_int_lstadd_back(t_stack *lst, t_stack *new)
{
	if (!lst)
		lst = new;
	else
		ft_int_lstlast(lst)->next = new;
}

int	ft_int_lstsize(t_stack *lst)
{
	int		len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}

void	check_duplicates(t_stack *lst, int n)
{
	while (lst)
	{
		if (n == lst->value)
			error_exit("Double value detected");
		lst = lst->next;
	}
}
