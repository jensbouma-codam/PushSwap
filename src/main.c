/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/19 17:18:01 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

int	main(int argc, char **argv)
{
	t_stacks	*s;
	int			i;

	if (argc >= ARG_MAX)
		exit_error("Too many arguments");
	if (argc <= 1)
		return (EXIT_SUCCESS);
	i = 0;
	s = (t_stacks *)safe_calloc(1, sizeof(*s));
	if (argc == 2)
		handle_arguments(&s, ft_split(argv[1], ' '), true);
	else
		handle_arguments(&s, argv + 1, false);
	sort(s);
	debug(s);
	clear_stacks(s);
	if (DEBUG > 2)
		system("leaks push_swap");
	return (EXIT_SUCCESS);
}
