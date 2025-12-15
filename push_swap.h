/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:37 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/15 15:39:00 by vdarsuye         ###   ########.fr       */
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

typedef struct s_cost_data
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
}	t_cost_data;

//parsing.c
int		is_sorted(t_node *stack);
void	parse_arguments(int argc, char **argv, t_node **a);
void	free_stack(t_node **stack);
void	choose_sort(int argc, t_node **a, t_node **b);

//check_utils.c
int		check_limits(t_node *head);
int		check_duplicates(t_node *head);
int		is_number(const char *str);
void	error_exit(void);

//cost.c
int		calculate_total_cost(t_node *a, t_node *b, int index_a);

//cost_utils.c
int		get_rotation_cost(t_node *stack, int index);
int		find_cheapest_in_a(t_node *a, t_node *b);
int		find_cheapest_in_b(t_node *a, t_node *b);
t_cost_data	init_data(t_node *a, int index_a, t_node *b, int index_b);

//move.c
void	move_to_top_a(t_node **a, int index);
void	move_to_top_b(t_node **b, int index);
void	move_both_to_top(t_node **a, t_node **b, int index_a, int index_b);

//stack.c
t_node	*create_node(long data);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
void	add_to_end(t_node **a, long data);
void	print_stack(t_node *stack);
void	put_index(t_node **a);

//utils.c
int		find_min(t_node *stack);
int		get_position(t_node *stack, int index);
int		get_min_index(t_node *stack);
int		get_max_index(t_node *stack);
void	put_index(t_node **a);

// Operations
// without print
void	swap(t_node **stack);
void	push(t_node **src, t_node **dest);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
// with print
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

//sorting.c
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
//void	radix_sort(t_node **a, t_node **b);
int		get_max_bits(int size);

// Turk algorithm functions
int		find_target_in_b(t_node *b, int index_a);
int		find_target_in_a(t_node *a, int index_b);
void	turk_sort(t_node **a, t_node **b);

// checker_utils_bonus.c
int		read_and_execute(t_node **a, t_node **b);

#endif
