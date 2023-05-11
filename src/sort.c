/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:00:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/11 19:21:48 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	if (DEBUG)
		ft_printf("Stack is sorted\n");
	return (true);
}

static void	sort_three(t_stacks *s)
{
	const int	first = s->a->value;
	const int	second = s->a->next->value;
	const int	last = s->a->next->next->value;

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
	const int	min = get_stack_min(s->a);
	const int	max = get_stack_max(s->a);

	while (!is_sorted(s->a) || s->len_stack_b)
	{
		if (s->a->value == max || s->a->value == min)
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
	const int	max = get_stack_min(s->a);
	int			i;

	ft_printf("Min: %i\n", max);
	i = 0;
	if (x == 33)
		exit_error("Error\n");
	if (DEBUG)
		ft_printf("Radix!");
	while (len_stack_a > i++)
	{
		if (bit_value(s->a->value - max, x) == 1)
			rotate_a(s);
		else
			push_ab(s);
	}
	x++;
	while (s->len_stack_b)
		push_ba(s);
	if (!is_sorted(s->a))
		radix_sort(s);
}

void	sort(t_stacks *s)
{
	if (s->len_stack_a == 2)
	{
		if (s->a->value > s->a->next->value)
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
