/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 00:19:50 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 11:32:22 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "colors.h"

void	*safe_calloc(size_t count, size_t size)
{
	int		tries;
	void	*ptr;

	tries = 0;
	while (tries < 10)
	{
		ptr = malloc(size * count + 1);
		if (ptr)
		{
			ft_bzero(ptr, size * count);
			return (ptr);
		}
		tries++;
	}
	if (DEBUG)
		ft_printf("%sAllocation of %i bytes failed after 10 tries%s\n",
			RED, (int)size * count, NORMAL);
	exit_error("Memmory allocation failed, Buy a new computer!");
	return (NULL);
}

void	clear_stacks(t_stacks *s)
{
	t_stack	*tmp;

	while (s->a)
	{
		if (DEBUG > 1)
			ft_printf("freeing %p\n", s->a);
		tmp = s->a;
		s->a = s->a->next;
		free(tmp);
	}
	while (s->b)
	{
		if (DEBUG > 1)
			ft_printf("freeing %p\n", s->b);
		tmp = s->b;
		s->b = s->b->next;
		free(tmp);
	}
	free(s);
}
