/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:20:04 by ahakobia          #+#    #+#             */
/*   Updated: 2024/10/10 19:12:56 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	free_before_exit(t_pixel *pixel)
{
	if (pixel->img)
		mlx_destroy_image(pixel->mlx, pixel->img);
	if (pixel->mlx_win)
		mlx_destroy_window(pixel->mlx, pixel->mlx_win);
	if (pixel->mlx)
	{
		mlx_destroy_display(pixel->mlx);
		free(pixel->mlx);
	}
	if (pixel->map)
		free_vertex(pixel->map, pixel);
	return (1);
}

void	free_parse(t_pixel *pixel, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(pixel->map[i]);
		i++;
	}
	free(pixel->map);
}
