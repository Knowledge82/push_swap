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
//reverse rotate
void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	prev = NULL;
	last = *a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	print_operation("rra");
}

void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	prev = NULL;
	last = *b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	print_operation("rrb");
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	print_operation("rrr");
}
