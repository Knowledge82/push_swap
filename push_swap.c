/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:54:54 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/14 16:10:39 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	parse_arguments(int argc, char **argv, t_node **a)
{
	int	i;

	i = 1;
	if (argc < 2)
		return ;
	while (i < argc)
	{
		if (is_number(argv[i]))
		{
			add_to_end(a, ft_atol(argv[i]));
			i++;
		}
		else
		{
			free_stack(a);
			error_exit();
		}
	}
}

void	free_stack(t_node **stack)
{
	t_node	*current;

	while (*stack)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

void	choose_sort(int argc, t_node **a, t_node **b)
{
	if (argc == 3)
		sort_two(a);
	else if (argc == 4)
		sort_three(a);
	else if ((argc == 5) || (argc == 6))
		sort_five(a, b);
	else
		turk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	parse_arguments(argc, argv, &a);
	check_duplicates(a);
	check_limits(a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	put_index(&a);
	if (argc > 1)
	{
		choose_sort(argc, &a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
