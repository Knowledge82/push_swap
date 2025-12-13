/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:41:15 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/13 17:17:03 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/

int	get_position(t_node *stack, int index)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

// Найти минимальный индекс в стеке
int	get_min_index(t_node *stack)
{
	int		min;
	t_node	*current;

	if (!stack)
		return (-1);
	min = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

// Найти максимальный индекс в стеке
int	get_max_index(t_node *stack)
{
	int		max;
	t_node	*current;

	if (!stack)
		return (-1);
	max = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;

void	put_index(t_node **a)
{
	t_node	*min_node;
	t_node	*current;
	int		index;
	int		min_value;
	int		size;

	size = stack_size(*a);
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
