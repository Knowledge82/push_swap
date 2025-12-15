/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:22:34 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/15 12:28:12 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_unsigned(unsigned int nb, int *len)
{
	if (nb >= 10)
		print_unsigned((nb / 10), len);
	print_char((nb % 10) + '0', len);
}
