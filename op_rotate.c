/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:05:05 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/07 12:37:18 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_silent(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

//rotate
void	ra(t_node **a)
{
	rotate_silent(a);
	print_operation("ra");
}

void	rb(t_node **b)
{
	rotate_silent(b);
	print_operation("rb");
}

void	rr(t_node **a, t_node **b)
{
	rotate_silent(a);
	rotate_silent(b);
	print_operation("rr");
}
