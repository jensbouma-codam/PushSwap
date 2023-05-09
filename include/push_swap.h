/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:52:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/09 11:29:03 by jensbouma     ########   odam.nl         */
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

// error_handler.c
void	exit_error(char *msg);
void	debug(t_stacks *s);

// input.c
// t_stack	*initialize_stack(int argc, char **argv);
// t_stack	*initialize_stack(int argc, char **argv);
t_stack	*initialize_stack(t_stacks **s, int argc, char **argv);
// t_stack	*initialize_stack(t_stack stack, int argc, char **argv);

// memory.c
void	*safe_calloc(size_t count, size_t size);
void	clear_stacks(t_stacks *s);

// stack.c
int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *stack);
t_stack	*add(t_stack *stack, int value);
t_stack	*addtop(t_stack *stack, int value);

// swap.c
int		swap_a(t_stacks *s);
int		swap_b(t_stacks *s);
int		swap_both(t_stacks *s);

// push.c
int		push_ba(t_stacks *s);
int		push_ab(t_stacks *s);

// rotate.c
int		rotate_a(t_stacks *s);
int		rotate_b(t_stacks *s);
int		rotate_both(t_stacks *s);

// rrotate.c
int		rrotate_a(t_stacks *s);
int		rrotate_b(t_stacks *s);
int		rrotate_both(t_stacks *s);
#endif
