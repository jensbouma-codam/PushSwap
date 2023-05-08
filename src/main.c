/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/08 19:27:04 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

int	main(int argc, char **argv)
{
	t_stacks	*s;

	s = (t_stacks *)safe_calloc(1, sizeof(*s));
	if (argc > 1)
	{
		s->a = initialize_stack(argc, argv);
		s->last_a = stack_last(s->a);
		s->size_a = stack_size(s->a);
		// s->b = add(s->b, 100);
		// s->b = add(s->b, 101);
		// s->b = add(s->b, 102);
		// s->b = add(s->b, 103);
		s->last_b = stack_last(s->b);
		s->size_b = stack_size(s->b);
		// swap_a(s);
		// swap_b(s);
		// push_ba(s);
		// swap_both(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ab(s);
		push_ba(s);
		push_ba(s);
		push_ba(s);
		// push_ab(s);
		// rotate_a(s);
		// rotate_a(s);
		// rotate_a(s);
		// rotate_a(s);
		// rotate_b(s);
		// rotate_both(s);
		// rotate_both(s);
		// rotate_both(s);
		// rotate_both(s);
		// rotate_both(s);
		// rotate_both(s);
		// rotate_both(s);
		// rotate_both(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_b(s);
		// rrotate_both(s);

		debug(s);
		// clear_stacks(s);
		if (DEBUG)
			system("leaks push_swap");
		return (EXIT_SUCCESS);
	}
	if (DEBUG)
		system("leaks push_swap");
	error_exit("No arguments given");
}
