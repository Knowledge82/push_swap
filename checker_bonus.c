/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:30:44 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/15 14:24:31 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_result(t_node *a, t_node *b)
{
	if (b == NULL && is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	parse_arguments(argc, argv, &a);
	check_duplicates(a);
	check_limits(a);
	if (read_and_execute(&a, &b) == -1)
	{
		free_stack(&a);
		free_stack(&b);
		error_exit();
	}
	print_result(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
