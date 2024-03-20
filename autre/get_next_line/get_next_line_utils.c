/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:40:06 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/24 23:13:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*copy;

	len = ft_strlen(s);
	copy = malloc(sizeof (char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s, len + 1);
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	ssize_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j + 1);
	free(s1);
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest || src)
	{
		while (n != 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n != 0)
	{
		n--;
		((unsigned char *)s)[n] = c;
	}
	return (s);
}
