/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:14:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 11:31:58 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "colors.h"

void	exit_error(char *msg)
{
	if (DEBUG)
		ft_printf("%sERROR\t%s%s\n", RED, msg, NORMAL);
	write(STDERR_FILENO, "Error\n", 6);
	exit (EXIT_FAILURE);
}


static void print_stack(t_stack *stack)
{
	while (stack)
	{
		if (stack->prev)
			ft_printf("Prev = %i Pointer = %p\t", stack->prev->value, stack->prev);
		else
			ft_printf("Prev = NULL\t\t\t");
		ft_printf("Value = %i \tPointer = %p\t", stack->value, stack);
		if (stack->next)
			ft_printf("Next = %i Pointer = %p\n", stack->next->value, stack->next);
		else
			ft_printf("Next = NULL\n");
		stack = stack->next;
	}
}

void	debug(t_stacks *s)
{
	// t_stack	*ta;
	// t_stack	*tb;

	if (!DEBUG)
		return ;
	ft_printf("\nA Len: %i\n\n", s->size_a);

	print_stack(s->a);
	if (s->last_a)
		ft_printf("last A: %i %p\n", s->last_a->value, s->last_a);
	
	ft_printf("\nB Len: %i\n\n", s->size_b);

	print_stack(s->b);
	if (s->last_b)
		ft_printf("last B: %i %p\n", s->last_b->value, s->last_b);
	
	// ta = s->a;
	// tb = s->b;
	// while (ta || tb)
	// {
	// 	if (!ta)
	// 		ft_printf("----\t\t");
	// 	else
	// 	{
	// 		ft_printf("%i %p\t\t", ta->value, ta->value);
	// 		if (ta->prev)
	// 			ft_printf("prev: %i %p\t", ta->prev->value, ta->prev);
	// 		else
	// 			ft_printf("prev: NULL\t");
	// 	}
	// 	if (!tb)
	// 		ft_printf("----\n");
	// 	else
	// 		ft_printf("%i %p\n", tb->value, tb->value);
	// 	if (ta)
	// 		ta = ta->next;
	// 	if (tb)
	// 		tb = tb->next;
	// }
}
