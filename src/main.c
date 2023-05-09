/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 11:36:27 by jensbouma     ########   odam.nl         */
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
		initialize_stack(&s, argc, argv);
		
		// push_ab(s);
		// // push_ab(s);
		// push_ab(s);
		// push_ab(s);
		// push_ab(s);
		// push_ab(s);
		// push_ab(s);
		// push_ab(s);
		// swap_both(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);

		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);

		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
		// swap_a(s);
			
		// swap_a(s);
		// swap_a(s);
		// swap_b(s);
		// swap_both(s); 
		// push_ba(s);
		// swap_both(s);
		// push_ab(s);
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
		rrotate_both(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_a(s);
		// rrotate_b(s);
		// rrotate_both(s);
		// push_ba(s);
		// push_ba(s);
		// push_ba(s);
		// push_ba(s);
		// push_ba(s);

		debug(s);
		clear_stacks(s);
		if (DEBUG)
			system("leaks push_swap");
		return (EXIT_SUCCESS);
	}
	if (DEBUG)
		system("leaks push_swap");
	exit_error("No arguments given");
}
