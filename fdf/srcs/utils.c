/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:17:46 by andrej            #+#    #+#             */
/*   Updated: 2024/04/10 13:56:43 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

int	free_vertex(t_vertex **str2d, t_pixel *pixel)
{
	int	i;

	i = 0;
	while (i < pixel->y_max && str2d[i])
	{
		free(str2d[i]);
		i++;
	}
	free(str2d);
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	n;
	int		k;

	k = 0;
	i = 0;
	n = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			k = 1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i++] - '0';
		if (n > LONG_MAX)
			return (-1);
	}
	if (k == 1)
		n *= -1;
	return (n);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (res);
}
