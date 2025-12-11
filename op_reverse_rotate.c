/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:07:09 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/07 12:38:42 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_silent(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

//reverse rotate
void	rra(t_node **a)
{
	reverse_rotate_silent(a);
	print_operation("rra");
}

void	rrb(t_node **b)
{
	reverse_rotate_silent(b);
	print_operation("rrb");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate_silent(a);
	reverse_rotate_silent(b);
	print_operation("rrr");
}
