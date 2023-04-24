/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:52:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/04/25 01:09:16 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define DEBUG 0

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

// error_handler.c
void	error_exit(char *msg);

// newtools.c
void	*safe_calloc(size_t count, size_t size);

// list.c
t_stack	*ft_int_lstnew(int value);
t_stack	*ft_int_lstlast(t_stack *lst);
void	ft_int_lstadd_back(t_stack *lst, t_stack *new);
int		ft_int_lstsize(t_stack *lst);
void	check_duplicates(t_stack *lst, int n);


// swap.c
int		sa(void);
int		sb(void);
int		ss(void);

#endif
