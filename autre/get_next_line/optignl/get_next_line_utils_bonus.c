/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:11:35 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/29 10:22:49 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

char	*ft_strjoin_free_s1(char *s1, char *s2, size_t n1, size_t n2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c, size_t n);

char	*ft_strjoin_free_s1(char *s1, char *s2, size_t n1, size_t n2)
{
	char	*str;
	size_t	l_s1;

	l_s1 = 0;
	if (s1)
		l_s1 = n2;
	str = malloc(sizeof(char) * (l_s1 + n1 + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, l_s1);
	ft_memcpy(str + l_s1, s2, n1);
	str[l_s1 + n1] = '\0';
	if (s1 != NULL)
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
