/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 23:14:57 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/01 22:30:56 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_int_lstnew(int value)
{
	t_stack	*node;
	int		*tmp;


	node = (t_stack *)safe_calloc(1, sizeof(*node));
	if (!node)
		error_exit("Memory allocation failed");
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

void	ft_int_lstadd_back(t_stack *lst, t_stack *add)
{
	if (!lst)
		lst = add;
	else
		ft_int_lstlast(lst)->next = add;
}

t_list	*ft_int_lstadd_front(t_list *lst, t_list *add)
{
	add->next = lst;
	lst = add;
	return (lst);
}

int	ft_int_lstsize(t_stack *lst)
{
	int		len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}

// void	check_duplicates(t_stack *lst, int n)
// {
// 	while (lst)
// 	{
// 		if (n == *lst->value)
// 			error_exit("Double value detected");
// 		lst = lst->next;
// 	}
// }
