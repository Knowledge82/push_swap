/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:37 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/18 13:40:02 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
//# include "LIBFT/ft_printf.h"

typedef struct s_node
{
	int				index;
	int				has_index;
	long			number;
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
//void	sort_large(t_node **a, t_node **b);
// Turk algorithm functions
void	turk_sort(t_node **a, t_node **b);
int		get_position(t_node *stack, int index);
int		get_min_index(t_node *stack);
int		get_max_index(t_node *stack);
int		find_target_in_b(t_node *b, int index_a);
int		find_target_in_a(t_node *a, int index_b);
int		get_rotation_cost(t_node *stack, int index);
int		calculate_total_cost_optimized(t_node *a, t_node *b, int index_a);
int		find_cheapest_in_a(t_node *a, t_node *b);
int		find_cheapest_in_b(t_node *a, t_node *b);
void	bring_to_top_a(t_node **a, int index);
void	bring_to_top_b(t_node **b, int index);
void	bring_both_to_top(t_node **a, t_node **b, int index_a, int index_b);

// Stack functions
t_node	*create_node(long data);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
void	add_to_end(t_node **a, long data);
void	print_stack(t_node *stack);
void	put_index(t_node **a);

// Utils
int		is_sorted(t_node *stack);
int		find_min(t_node *stack);
void	move_to_top(t_node **a, int min_index);
void	error_exit(void);
int		is_number(const char *str);
int		check_duplicates(t_node *head);
int		check_limits(t_node *head);
void	print_operation(char *operation);
void	choose_sort(int argc, t_node **a, t_node **b);
int		get_max_bits(int size);

#endif
