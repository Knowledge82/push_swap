/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:27:01 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/12/18 13:13:17 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limits(t_node *head)
{
	while (head)
	{
		if (head->number > INT_MAX || head->number < INT_MIN)
			error_exit();
		head = head->next;
	}
	return (0);
}

int	check_duplicates(t_node *head)
{
	t_node	*outer;
	t_node	*inner;

	outer = head;
	while (outer != NULL)
	{
		inner = outer->next;
		while (inner != NULL)
		{
			if (outer->number == inner->number)
				error_exit();
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_operation(char *operation)
{
	printf("%s\n", operation);
}
