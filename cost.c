/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:57:36 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/14 18:34:22 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

static int	get_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static int	calc_same_direction(t_cost_data *data)
{
	int	cost_rr;
	int	cost_rrr;

	cost_rr = get_max(data->pos_a, data->pos_b);
	cost_rrr = get_max(data->size_a - data->pos_a, data->size_b - data->pos_b);
	return (get_min(cost_rr, cost_rrr));
}

static int	calc_diff_direction(t_cost_data *data)
{
	int	cost_ra_rrb;
	int	cost_rra_rb;

	cost_ra_rrb = data->pos_a + (data->size_b - data->pos_b);
	cost_rra_rb = (data->size_a - data->pos_a) + data->pos_b;
	return (get_min(cost_ra_rrb, cost_rra_rb));
}

int	calculate_total_cost(t_node *a, t_node *b, int index_a)
{
	t_cost_data	data;
	int			target_b;
	int			cost_same;
	int			cost_diff;

	target_b = find_target_in_b(b, index_a);
	data = init_data(a, index_a, b, target_b);
	cost_same = calc_same_direction(&data);
	cost_diff = calc_diff_direction(&data);
	return (get_min(cost_same, cost_diff));
}
