/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:17:08 by andrej            #+#    #+#             */
/*   Updated: 2024/04/10 07:59:39 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stddef.h>
#include <stdlib.h>

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c && s[i])
		{
			words++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else if (s[i])
			i++;
	}
	return (words);
}

size_t	word_len(size_t i, char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

void	*total_free(char **str2d)
{
	size_t	i;

	i = 0;
	while (str2d[i])
	{
		free(str2d[i]);
		i++;
	}
	free(str2d);
	return (NULL);
}

char	**fill_words(char **str2d, size_t words, char const *s, char c)
{
	size_t	i;	
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] == c)
			i++;
		str2d[j] = malloc(sizeof(char) * (word_len(i, s, c) + 1));
		if (!str2d[j])
			return (total_free(str2d));
		k = 0;
		while (s[i] && s[i] != c)
		{
			str2d[j][k] = s[i];
			i++;
			k++;
		}
		str2d[j][k] = '\0';
		j++;
	}
	str2d[j] = 0;
	return (str2d);
}

char	**ft_split(char const *s, char c)
{
	char	**str2d;
	size_t	words;

	if (!s)
		return (0);
	words = count_words(s, c);
	str2d = malloc(sizeof(char *) * (words + 1));
	if (!str2d)
		return (NULL);
	return (fill_words(str2d, words, s, c));
}
