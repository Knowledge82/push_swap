/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:08:42 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/14 18:15:10 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Находит куда вставить элемент из A в стек B.
   Target = наибольший элемент в B, который МЕНЬШЕ нашего
   Если таких нет → target = МАКСИМУМ в B */
int	find_target_in_b(t_node *b, int index_a)
{
	int		target;
	t_node	*current;
	int		found;

	if (!b)
		return (-1);
	target = INT_MIN;
	found = 0;
	current = b;
	while (current)
	{
		if (current->index < index_a)
		{
			if (!found || current->index > target)
			{
				target = current->index;
				found = 1;
			}
		}
		current = current->next;
	}
	if (!found)
		target = get_max_index(b);
	return (target);
}

/* Находит target в стеке A для элемента из B
 * Target = минимальный элемент в А, который больше текущего
 * если таких нет, то target = минимальный элемент в A
 */
int	find_target_in_a(t_node *a, int index_b)
{
	int		target;
	t_node	*current;
	int		found;

	if (!a)
		return (-1);
	target = INT_MAX;
	found = 0;
	current = a;
	while (current)
	{
		if (current->index > index_b)
		{
			if (!found || current->index < target)
			{
				target = current->index;
				found = 1;
			}
		}
		current = current->next;
	}
	if (!found)
		target = get_min_index(a);
	return (target);
}

void	turk_sort(t_node **a, t_node **b)
{
	int	cheapest_index;
	int	target_index;

	if (stack_size(*a) > 3)
		pb(a, b);
	if (stack_size(*a) > 3)
		pb(a, b);
	while (stack_size(*a) > 3)
	{
		cheapest_index = find_cheapest_in_a(*a, *b);
		target_index = find_target_in_b(*b, cheapest_index);
		move_both_to_top(a, b, cheapest_index, target_index);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		cheapest_index = find_cheapest_in_b(*a, *b);
		target_index = find_target_in_a(*a, cheapest_index);
		move_both_to_top(a, b, target_index, cheapest_index);
		pa(b, a);
	}
	cheapest_index = get_min_index(*a);
	move_to_top_a(a, cheapest_index);
}
