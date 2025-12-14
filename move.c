/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:14:45 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/14 18:32:51 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_node **a, int index)
{
	int	pos;
	int	size;

	pos = get_position(*a, index);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->index != index)
			ra(a);
	}
	else
	{
		while ((*a)->index != index)
			rra(a);
	}
}

void	move_to_top_b(t_node **b, int index)
{
	int	pos;
	int	size;

	pos = get_position(*b, index);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while ((*b)->index != index)
			rb(b);
	}
	else
	{
		while ((*b)->index != index)
			rrb(b);
	}
}

void	move_both_to_top(t_node **a, t_node **b, int index_a, int index_b)
{
	t_cost_data	data;

	data = init_data(*a, index_a, *b, index_b);
	while (data.pos_a > 0 && data.pos_b > 0 && data.pos_a
		<= data.size_a / 2 && data.pos_b <= data.size_b / 2)
	{
		rr(a, b);
		data.pos_a--;
		data.pos_b--;
	}
	while (data.pos_a > 0 && data.pos_b > 0 && data.pos_a
		> data.size_a / 2 && data.pos_b > data.size_b / 2)
	{
		rrr(a, b);
		data.pos_a++;
		data.pos_b++;
		if (data.pos_a >= data.size_a)
			data.pos_a = 0;
		if (data.pos_b >= data.size_b)
			data.pos_b = 0;
	}
	move_to_top_a(a, index_a);
	move_to_top_b(b, index_b);
}
