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
//rotate
void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	*a = first->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	print_operation("ra");
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	*b = first->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	print_operation("rb");
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	print_operation("rr");
}
