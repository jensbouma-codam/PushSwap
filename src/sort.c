/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:00:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/10 18:53:19 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	manual_operations(t_stacks *s)
{
	char	c;

	debug(s);
	c = getchar();
	if (c == 's')
		push_ab(s);
	if (c == 'a')
		push_ba(s);
	if (c == 'q')
		rrotate_a(s);
	if (c == 'w')
		rrotate_b(s);
	if (c == 'z')
		rotate_a(s);
	if (c == 'x')
		rotate_b(s);
	if (c == 'e')
		swap_a(s);
	if (c == 'c')
		swap_b(s);
}

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

	while (!is_sorted(s->a) || s->size_b)
	{
		if (s->a->value == max || s->a->value == min)
			push_ab(s);
		if (s->size_a == 3)
		{
			sort_three(s);
			while (s->size_b)
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

static int	bit_value(int n, int x)
{
	int	bits;
	int	i;

	i = 1;
	bits = (sizeof(n) << 3);
	while (i <= bits)
		ft_printf("%d", (int)(n >> (bits - i++)) & 1);
	ft_printf("\n");
	ft_printf("Bit postitie %d: ", x);
	if ((n >> x) & 1)
	{
		ft_printf("1\n");
		return (1);
	}
	ft_printf("0\n");
	return (0);
}

static void	radix_sort(t_stacks *s)
{
	static int	x = 0;
	int			i;

	i = 0;
	if (x == 32)
		exit_error("Error\n");
	while (s->size_a > i)
	{
		ft_printf("Value : %d\n", s->a->value);
		if (bit_value(s->a->value, x) == 1)
		{
			push_ab(s);
			i = 0;
		}
		else
		{
			rotate_a(s);
			i++;
		}
		debug(s);
		read(1, NULL, 1);
	}
	
	x++;
	if (!is_sorted(s->a) && s->size_a)
		radix_sort(s);
	while (s->size_b)
		push_ba(s);
	if (!is_sorted(s->a) && s->size_a)
		radix_sort(s);
	debug(s);
}

// Binary
// OF push > b or rotate A
// 1 > rotate 0 > push_ab

void	sort(t_stacks *s)
{
	if (s->size_a == 2)
	{
		if (s->a->value > s->a->next->value)
			swap_a(s);
	}
	else if (s->size_a == 3)
		sort_three(s);
	else if (s->size_a <= 5)
		sort_four_five(s);
	else
		radix_sort(s);
	exit_error("Not implemented yet\n");



	while (!is_sorted(s->a) || s->b)
		manual_operations(s);
	return ;
}
