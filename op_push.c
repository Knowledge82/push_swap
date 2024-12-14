/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:03:43 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/07 16:20:25 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//push
void	pa(t_node **b, t_node **a)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	print_operation("pa");
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = *b;
	*b = temp;
	print_operation("pb");
}
