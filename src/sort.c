/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:00:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 12:47:43 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks **s)
{
	int	i;

	i = 0;
	if (DEBUG)
		ft_printf("Sorting %p\n", (*s)->a);
	while (i)
	{
		if ((*s)->a->value > i)
		{
			rotate_a((*s));
			i++;
		}
		else
		{
			push_ab((*s));
			i++;
		}
	}
	return ;
}
