/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:14:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/08 11:21:33 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "colors.h"

void	error_exit(char *msg)
{
	if (DEBUG)
		ft_printf("%sERROR\t%s%s\n", RED, msg, NORMAL);
	write(STDERR_FILENO, "Error\n", 6);
	exit (EXIT_FAILURE);
}
p_error();


void	debug(t_stack *stack_a, t_stack *stack_b)
{
	if (DEBUG)
	{
		ft_printf("\n\nDEBUG:\nStack A\t\tStackB\nLen: %i\t\tLen: %i\n\n", 0 ,0 );
		// 	ft_int_lstsize(stack_a), ft_int_lstsize(stack_b));
		while (stack_a || stack_b)
		{
			if (stack_a)
			{
				ft_printf("%i %p\t\t", stack_a->value, stack_a->value);
				stack_a = stack_a->next;
			}
			else
				ft_printf("----\t\t");
			if (stack_b)
			{
				ft_printf("%i %p\n", stack_b->value, stack_b->value);
				stack_b = stack_b->next;
			}
			else
				ft_printf("----\n");
		}
	}
}
