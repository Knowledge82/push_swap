/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:37 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/14 15:25:03 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"

typedef struct s_node
{
	int		index;
	int		has_index;
	int		number;
	struct s_node	*next;
}	t_node;

// Operations
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

// Sort functions
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sort_large(t_node **a, t_node **b);

// Stack functions
t_node	*create_node(int data);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
void	add_to_end(t_node **a, int data);
void	print_stack(t_node *stack);
void	put_index(t_node **a);

// Utils
int		is_sorted(t_node *stack);
int		find_min(t_node *stack);
int		find_max(t_node *stack);
void	move_to_top(t_node **a, int min_index);
void	move_back(t_node **a, t_node **b);
void	error_exit(void);
int		is_number(const char *str);
int		check_duplicates(t_node *head);
int		check_limits(t_node *head);
void	print_operation(char *operation);
void	choose_sort(int argc, t_node **a, t_node **b);

#endif
