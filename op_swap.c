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

//swap
void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	print_operation("sa");
}

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	print_operation("sb");
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	print_operation("ss");
}
