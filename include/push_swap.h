/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:52:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/11 18:36:00 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

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
	int		len_stack_a;

	t_stack	*b;
	t_stack	*last_b;
	int		len_stack_b;
}			t_stacks;

// debug.c
int		actions;
void	exit_error(char *msg);
void	debug(t_stacks *s);

// input.c
void	handle_arguments(t_stacks **s, int argc, char **argv);

// memory.c
void	*safe_calloc(size_t count, size_t size);
void	clear_stacks(t_stacks *s);

// utils.c
int		get_int_length(int n);
int		bit_value(long n, int x);

// stack.c
int		get_stack_max(t_stack *stack);
int		get_stack_min(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*add(t_stack *stack, long value);

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
