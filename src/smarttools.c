/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newtools.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 00:19:50 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/25 00:20:09 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*safe_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count + 1);
	if (!ptr)
		error_exit("Memmory allocation failed");
	ft_bzero(ptr, size * count);
	return (ptr);
}
