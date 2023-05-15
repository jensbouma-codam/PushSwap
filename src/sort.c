/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:00:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/15 16:32:42 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_three(t_stacks *s)
{
	const int	first = s->a->index;
	const int	second = s->a->next->index;
	const int	last = s->a->next->next->index;

	if (first > last && second < last)
		rotate_a(s);
	else if (first > last && second > last)
	{
		if (first > second)
			swap_a(s);
		rrotate_a(s);
	}
	if (!is_sorted(s->a))
		swap_a(s);
	if (!is_sorted(s->a))
	{
		if (first > last)
			rrotate_a(s);
		else if (!is_sorted(s->a))
			rotate_a(s);
	}
}

static void	sort_four_five(t_stacks *s)
{
	while (!is_sorted(s->a) || s->len_stack_b)
	{
		if (s->a->value == get_stack_max(s->a)
			|| s->a->value == get_stack_min(s->a))
			push_ab(s);
		if (s->len_stack_a == 3)
		{
			sort_three(s);
			while (s->len_stack_b)
			{
				push_ba(s);
				if (!is_sorted(s->a))
					rotate_a(s);
			}
			return ;
		}
		rotate_a(s);
	}
	return ;
}

static void	radix_sort(t_stacks *s)
{
	static int	x = 0;
	const int	len_stack_a = s->len_stack_a;
	int			i;

	i = 0;
	while (len_stack_a > i++ && !(is_sorted(s->a)))
	{
		if (bit_value(s->a->index, x) == 1)
			rotate_a(s);
		else
			push_ab(s);
	}
	x++;
	i = s->len_stack_b;
	while (i--)
	{
		if (bit_value(s->b->index, x) == 1
			|| x > (int)(sizeof(s->b->index) << 3))
			push_ba(s);
		else if (!is_rev_sorted(s->b))
			rotate_b(s);
	}
	if (!is_sorted(s->a) || s->len_stack_b)
		radix_sort(s);
}

void	sort(t_stacks *s)
{
	add_index(s->a);
	if (s->len_stack_a == 2)
	{
		if (s->a->index > s->a->next->index)
			swap_a(s);
	}
	else if (s->len_stack_a == 3)
		sort_three(s);
	else if (s->len_stack_a <= 5)
		sort_four_five(s);
	else
		radix_sort(s);
	return ;
}
