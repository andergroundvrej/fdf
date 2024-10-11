/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:08:23 by andrej            #+#    #+#             */
/*   Updated: 2024/04/10 14:05:32 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

int	fill_tab(char *str, int y, t_pixel *pixel)
{
	int	i;

	i = 0;
	while (*str && *str != '\n')
	{
		ft_memset(&pixel->map[y][i], 0, sizeof(t_vertex));
		pixel->map[y][i].z = ft_atol(str) * 5;
		pixel->map[y][i].y = y;
		pixel->map[y][i].x = i;
		++i;
		while (*str && *str != '\n')
		{
			if (*str == ' ')
			{
				while (*str == ' ')
					++str;
				break ;
			}
			++str;
		}
	}
	ft_memset(&pixel->map[y][i], 0, sizeof(t_vertex));
	return (0);
}

int	fill_line(t_pixel *pixel, int y, char *str)
{
	pixel->x_max = (int)count_words(str, ' ');
	pixel->map[y] = malloc(sizeof(t_vertex) * (pixel->x_max + 2));
	if (pixel->map[y] == NULL)
	{
		free_parse(pixel, y);
		return (1);
	}
	fill_tab(str, y, pixel);
	return (0);
}

int	fill_z(t_pixel *pixel, const char *av, int y)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (fill_line(pixel, y, line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	return (0);
}

int	parsing(const char *av, t_pixel *pixel)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	pixel->y_max = 0;
	pixel->x_max = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		pixel->y_max++;
		free(line);
		line = get_next_line(fd);
	}
	pixel->map = malloc(sizeof(t_vertex *) * pixel->y_max);
	if (pixel->map == NULL)
		return (1);
	if (fill_z(pixel, av, y) == 1)
		return (1);
	return (0);
}
