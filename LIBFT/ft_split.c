/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:18:15 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/07/20 18:32:12 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char *start, const char *end)
{
	size_t	len_word;
	char	*word;

	len_word = end - start;
	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len_word + 1);
	return (word);
}

static void	free_memory(char **arr, size_t index)
{
	size_t	n;

	n = 0;
	while (n < index)
	{
		free(arr[n]);
		n++;
	}
	free(arr);
}

static int	split_words(char **dest, const char *s, char c)
{
	const char	*start;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			dest[i] = extract_word(start, s);
			if (!dest[i])
			{
				free_memory(dest, i);
				return (0);
			}
			i++;
		}
	}
	dest[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc((num_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (!split_words(dest, s, c))
	{
		free_memory(dest, num_words(s, c));
		return (NULL);
	}
	return (dest);
}
