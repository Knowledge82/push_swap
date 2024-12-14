/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:06:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/14 16:15:29 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	sa(a);
}

void	sort_three(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *a;
	second = (*a)->next;
	third = second->next;
	if (first->number > second->number && first->number > third->number)
		ra(a);
	if (second->number > third->number)
		rra(a);
	if (first->number > second->number)
		sa(a);
}

void	sort_five(t_node **a, t_node **b)
{
	int	size;
	int	min_index;

	size = stack_size(*a);
	while (size > 3)
	{
		min_index = find_min(*a);
		move_to_top(a, min_index);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(b, a);
	return ;
}

void	sort_large(t_node **a, t_node **b)
{
	int	size;
	int	bit_pos;
	int	count;

	size = stack_size(*a);
	bit_pos = 1;
	while (!is_sorted(*a))
	{
		count = 0;
		while (*a != NULL && count < size)
		{
			if (((*a)->index & bit_pos) == 0)
				pb(a, b);
			else
				ra(a);
			count++;
		}
		while (*b != NULL)
			pa(b, a);
		bit_pos = bit_pos * 2;
	}
}
