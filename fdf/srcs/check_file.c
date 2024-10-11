/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 03:22:33 by ahakobia          #+#    #+#             */
/*   Updated: 2024/04/09 03:22:50 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char *file)
{
	char	*end;
	char	*start;

	end = ft_strrchr(file, '.');
	start = ft_strrchr(file, '/');
	if (end && ft_strlen(file) > 4)
	{
		if (start)
		{
			if (ft_strlen(end) < ft_strlen(start) && \
				ft_strcmp(end, ".fdf") == 0)
				return (0);
		}
		else
		{
			if (ft_strlen(end) < ft_strlen(file) && ft_strcmp(end, ".fdf") == 0)
				return (0);
		}
	}
	return (-1);
}
