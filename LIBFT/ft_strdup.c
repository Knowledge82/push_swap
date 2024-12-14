/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:27:09 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/07/15 15:40:04 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;
	char	*ptr_s;

	len = ft_strlen(s);
	new_s = malloc((len + 1) * sizeof(char));
	ptr_s = new_s;
	if (new_s == NULL)
		return (NULL);
	while (*s)
	{
		*ptr_s = *s;
		ptr_s++;
		s++;
	}
	*ptr_s = '\0';
	return (new_s);
}
