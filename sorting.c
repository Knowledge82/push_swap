/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:06:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/18 13:34:18 by vdarsuye         ###   ########.fr       */
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
	if (first->number > second->number && second->number > third->number)
	{
		sa(a);
		rra(a);
	}
	else if (first->number > third->number && third->number > second->number)
		ra(a);
	else if (second->number > first->number && first->number > third->number)
		rra(a);
	else if (second->number > third->number && third->number > first->number)
	{
		sa(a);
		ra(a);
	}
	else if (third->number > first->number && first->number > second->number)
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

int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	sort_large(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = get_max_bits(size);
	
	printf("DEBUG: max_bits = %d\n", max_bits);  // ОТЛАДКА

	i = 0;
	while (i < max_bits)
	{

		printf("DEBUG: проход %d\n", i);  // ОТЛАДКА

		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b != NULL)
			pa(b, a);
		i++;
	}

	printf("DEBUG: всего проходов: %d\n", i);  // ОТЛАДКА

}
