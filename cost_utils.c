/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:03:09 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/14 18:55:59 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation_cost(t_node *stack, int index)
{
	int	pos;
	int	size;
	int	cost_ra;
	int	cost_rra;

	pos = get_position(stack, index);
	size = stack_size(stack);
	if (pos == -1)
		return (0);
	cost_ra = pos;
	cost_rra = size - pos;
	if (cost_ra < cost_rra)
		return (cost_ra);
	return (cost_rra);
}

int	find_cheapest_in_a(t_node *a, t_node *b)
{
	t_node	*current;
	int		cost;
	int		min_cost;
	int		cheapest_index;

	current = a;
	min_cost = INT_MAX;
	cheapest_index = current->index;
	while (current)
	{
		cost = calculate_total_cost(a, b, current->index);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_index = current->index;
		}
		current = current->next;
	}
	return (cheapest_index);
}

int	find_cheapest_in_b(t_node *a, t_node *b)
{
	t_node	*current;
	int		cost;
	int		min_cost;
	int		cheapest_index;
	int		target_a;

	current = b;
	min_cost = INT_MAX;
	cheapest_index = current->index;
	while (current)
	{
		target_a = find_target_in_a(a, current->index);
		cost = get_rotation_cost(b, current->index)
			+ get_rotation_cost(a, target_a);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_index = current->index;
		}
		current = current->next;
	}
	return (cheapest_index);
}

t_cost_data	init_data(t_node *a, int index_a, t_node *b, int index_b)
{
	t_cost_data	data;

	data.pos_a = get_position(a, index_a);
	data.pos_b = get_position(b, index_b);
	data.size_a = stack_size(a);
	data.size_b = stack_size(b);
	return (data);
}
