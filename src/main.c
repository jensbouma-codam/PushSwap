/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/15 15:54:52 by jbouma        ########   odam.nl         */
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
	debug(s);
	clear_stacks(s);
	if (DEBUG > 2)
		system("leaks push_swap");
	write(1, "OK\n", 3);
	return (EXIT_SUCCESS);
}
