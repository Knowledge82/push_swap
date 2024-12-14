/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:41:15 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/14 18:16:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack)
{
	int		i;
	int		min_index;
	int		min_value;
	t_node	*current;

	if (stack == NULL)
		return (-1);
	current = stack;
	min_index = 0;
	min_value = stack->number;
	i = 0;
	while (current)
	{
		if (current->number < min_value)
		{
			min_value = current->number;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

int	find_max(t_node *stack)
{
	int	max_value;

	max_value = stack->number;
	while (stack != NULL)
	{
		if (stack->number > max_value)
			max_value = stack->number;
		stack = stack->next;
	}
	return (max_value);
}

void	move_to_top(t_node **a, int min_index)
{
	int	size;

	size = stack_size(*a);
	if (min_index == 0)
		return ;
	if (min_index > size / 2)
	{
		while (min_index < size)
		{
			rra(a);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
}

void	move_back(t_node **a, t_node **b)
{
	while (*b)
		pa(a, b);
}

void	put_index(t_node **a)
{
	t_node	*min_node;
	t_node	*current;
	int		index;
	int		min_value;
	int		size;

	size = stack_size(*a);
	min_node = *a;
	current = *a;
	index = 0;
	while (index < size)
	{
		min_value = INT_MAX;
		current = *a;
		while (current != NULL)
		{
			if (current->number < min_value && current->has_index == 0)
			{
				min_node = current;
				min_value = current -> number;
			}
			current = current->next;
		}
		min_node->index = index;
		min_node->has_index = 1;
		index++;
	}
}
