/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:30:58 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/15 14:49:43 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_swap_push(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(line, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(a, b);
	else
		return (0);
	return (1);
}

static int	exec_rotate(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

static int	execute_instructions(char *line, t_node **a, t_node **b)
{
	if (exec_swap_push(line, a, b))
		return (1);
	if (exec_rotate(line, a, b))
		return (1);
	return (0);
}

int	read_and_execute(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (!execute_instructions(line, a, b))
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}
