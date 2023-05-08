/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:52:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/02 00:14:21 by jensbouma     ########   odam.nl         */
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
void	error_exit(char *msg);
void	debug(t_stack *stack_a, t_stack *stack_b);

// newtools.c
void	*safe_calloc(size_t count, size_t size);

// // list.c
// t_stack	*ft_int_lstnew(int value);
// t_stack	*ft_int_lstlast(t_stack *lst);
// void	ft_int_lstadd_back(t_stack *lst, t_stack *add);
// t_list	*ft_int_lstadd_front(t_list *lst, t_list *add);
// int		ft_int_lstsize(t_stack *lst);
// void	check_duplicates(t_stack *lst, int n);


// // void	swap(int x, int y);

// // swap.c
// int		sa(t_stack *stack);
// int		sb(t_stack *stack);
// int		ss(t_stack *a, t_stack *b);

// // push.c
// int		pa(t_stack *a, t_stack *b);
// t_stack	*pb(t_stack *a, t_stack *b);
#endif
