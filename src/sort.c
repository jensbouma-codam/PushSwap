/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:00:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 19:06:10 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static int	get_max_digits(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->value;
	i = 0;
	while (stack && stack->value)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	while (max / 10 > 0)
	{
		max /= 10;
		i++;
	}
	return (i);
}

// static bool	is_sorted(t_stack *stack)
// {
// 	while (stack && stack->next)
// 	{
// 		if (stack->value > stack->next->value)
// 			return (false);
// 		stack = stack->next;
// 	}
// 	if (DEBUG)
// 		ft_printf("Stack is sorted\n");
// 	return (true);
// }

static void	sort_lasts(t_stacks *s, int run)
{
	int	i;

	i = 0;
	ft_printf("run = %i\n", run);
	while (s->a->length < run)
	{
		ft_printf("pushing %i\n", s->a->length);
		ft_printf("pushing %i\n", s->a->value % i);
		rotate_a(s);
	}

	return ;
}

void	sort(t_stacks *s)
{
	int		run;

	run = get_max_digits(s->a)  +1;
	if (DEBUG)
		ft_printf("digits = %d\n", run);

	while (run >= 0)
	{

		sort_lasts((s), run);
	// 	// while ((*s)->a->length > run)
	// 	// 	push_ab(*s);
	// 	// if (get_max_digits((*s)->a) > run)
	// 	// {
	// 	// 	rrotate_a(*s);
	// 	// 	sort(s);
	// 	// }
		run--;
	}
	
	// while (!is_sorted(s->a) || s->b)
	// {
	// 	if (s->a->value > s->a->next->value)
	// 		push_ab(s);
	// 	else
	// 		rrotate_a(s);
	// 	debug(s);
	// }
	return ;
}

// char	c;
	// while(true)
	// {
	// 	debug(s);
	// 	c = getchar();
	// 	if (c == 's')
	// 		push_ab(s);
	// 	if (c == 'a')
	// 		push_ba(s);
	// 	if (c == 'q')
	// 		rrotate_a(s);
	// 	if (c == 'w')
	// 		rrotate_b(s);
	// 	if (c == 'z')
	// 		rotate_a(s);
	// 	if (c == 'x')
	// 		rotate_b(s);

	// }