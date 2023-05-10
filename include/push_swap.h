/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:52:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 16:16:10 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define DEBUG 1

# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# include "../lib/LibFT/include/libft.h"

typedef struct s_stack
{
	int				value;
	int				length;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*last_a;
	int		size_a;

	t_stack	*b;
	t_stack	*last_b;
	int		size_b;
}			t_stacks;

// debug.c
void	exit_error(char *msg);
void	debug(t_stacks *s);

// input.c
void	handle_arguments(t_stacks **s, int argc, char **argv);

// memory.c
void	*safe_calloc(size_t count, size_t size);
void	clear_stacks(t_stacks *s);

// stack.c
// int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *stack);
t_stack	*add(t_stack *stack, int value);
t_stack	*addtop(t_stack *stack, int value);

// swap.c
void	swap_a(t_stacks *s);
void	swap_b(t_stacks *s);
void	swap_both(t_stacks *s);

// push.c
void	push_ba(t_stacks *s);
void	push_ab(t_stacks *s);

// rotate.c
void	rotate_a(t_stacks *s);
void	rotate_b(t_stacks *s);
void	rotate_both(t_stacks *s);

// rrotate.c
void	rrotate_a(t_stacks *s);
void	rrotate_b(t_stacks *s);
void	rrotate_both(t_stacks *s);

// sort.c
void	sort(t_stacks *s);
#endif
