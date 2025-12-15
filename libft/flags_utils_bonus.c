/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:03:13 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/15 13:03:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_flags(t_flags *flags)
{
	ft_memset(flags, 0, sizeof(t_flags));
	flags->has_prec = -1;
	flags->no_flags = 1;
}

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#'
		|| c == '+' || c == ' ');
}
