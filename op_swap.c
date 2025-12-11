/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:01:09 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/07 12:37:59 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_silent(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

//swap
void	sa(t_node **a)
{
	swap_silent(a);
	print_operation("sa");
}

void	sb(t_node **b)
{
	swap_silent(b);
	print_operation("sb");
}

void	ss(t_node **a, t_node **b)
{
	swap_silent(a);
	swap_silent(b);
	print_operation("ss");
}
