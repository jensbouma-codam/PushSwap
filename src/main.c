/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 16:49:26 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

int	main(int argc, char **argv)
{
	t_stacks	*s;

	s = (t_stacks *)safe_calloc(1, sizeof(*s));
	handle_arguments(&s, argc, argv);
	sort(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	// rrotate_a(s);
	// swap_a(s);
	debug(s);
	clear_stacks(s);
	if (DEBUG)
		system("leaks push_swap");
	return (EXIT_SUCCESS);
}

// rra
// sa
// rra
// sa
// rra
// sa
// rra
// sa
// rra
// sa
// rra
// sa
// rra
// sa
// rra
// sa