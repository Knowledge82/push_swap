/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:34 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/15 12:28:12 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(char *str, int *len)
{
	if (str == NULL)
		return (print_str("(null)", len));
	while (*str)
	{
		print_char(*str, len);
		str++;
	}
}
