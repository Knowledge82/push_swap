/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:23:12 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/18 12:43:09 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(long data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_printf("Error: memory allocation failed\n");
		exit(1);
	}
	new_node->number = data;
	new_node->next = NULL;
	new_node->has_index = 0;
	return (new_node);
}

void	add_to_end(t_node **a, long data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(data);
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	current = *a;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int	stack_size(t_node *a)
{
	int		size;
	t_node	*current;

	size = 0;
	current = a;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->number);
		stack = stack->next;
	}
	ft_printf("\n");
}
