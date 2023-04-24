/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:14:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/25 00:10:18 by jensbouma     ########   odam.nl         */
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
