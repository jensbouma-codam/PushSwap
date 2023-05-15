/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:14:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/15 16:16:21 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "colors.h"

void	exit_error(char *msg)
{
	if (DEBUG)
		ft_printf("%sERROR\t%s%s\n", RED, msg, NORMAL);
	write(STDERR_FILENO, "Error\n", 6);
	if (DEBUG > 2)
		system("leaks push_swap");
	exit (EXIT_FAILURE);
}

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		if (stack->prev)
			ft_printf("Prev = %i Pointer = %p\t",
				stack->prev->value, stack->prev);
		else
			ft_printf("Prev = NULL\t\t\t");
		ft_printf("Value = %i \tPointer = %p\t",
			stack->value, stack);
		if (stack->next)
			ft_printf("Next = %i Pointer = %p\n",
				stack->next->value, stack->next);
		else
			ft_printf("Next = NULL\n");
		stack = stack->next;
	}
}

void	debug(t_stacks *s)
{
	if (!DEBUG)
		return ;
	ft_printf("\nA Len: %i\n\n", s->len_stack_a);
	print_stack(s->a);
	if (s->last_a)
		ft_printf("last A: %i %p\n", s->last_a->value, s->last_a);
	ft_printf("\nB Len: %i\n\n", s->len_stack_b);
	print_stack(s->b);
	if (s->last_b)
		ft_printf("last B: %i %p\n", s->last_b->value, s->last_b);
}
