/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 05:33:06 by ahakobia          #+#    #+#             */
/*   Updated: 2024/04/10 12:19:23 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_value(t_pixel *pixel, int j, int k)
{
	pixel->y = 0;
	while (pixel->y < pixel->y_max)
	{
		pixel->x = 0;
		while (pixel->x < pixel->x_max)
		{
			pixel->map[pixel->y][pixel->x].x_p = (SQRT2 * pixel->map[pixel->y]
				[pixel->x].x - SQRT2 * pixel->map[pixel->y][pixel->x].y) * 0.5;
			if (pixel->map[pixel->y][pixel->x].z > 100)
				pixel->map[pixel->y][pixel->x].z *= 0.2;
			if (pixel->map[pixel->y][pixel->x].z < -100)
				pixel->map[pixel->y][pixel->x].z *= 0.2;
			pixel->map[pixel->y][pixel->x].y_p = ((0.816497 * -pixel->map
					[pixel->y][pixel->x].z)) - 0.408248 * (pixel->map
				[pixel->y][pixel->x].x + pixel->map[pixel->y][pixel->x].y);
			pixel->map[pixel->y][pixel->x].x_p = ((pixel->map[pixel->y]
					[pixel->x].x_p) + (WIDTH / 2)) + (k * ((pixel->x)
						- (pixel->x_max / 2.2)));
			pixel->map[pixel->y][pixel->x].y_p = ((pixel->map[pixel->y]
					[pixel->x].y_p) + (HEIGHT / 2)) + (j * ((pixel->y)
						- (pixel->y_max / 2.2)));
			pixel->x++;
		}
		pixel->y++;
	}
}

int	apply_projection(t_pixel *pixel)
{
	int	k;
	int	j;

	k = ((WIDTH * 0.95) / pixel->x_max) / 1.5;
	j = ((HEIGHT * 0.95) / pixel->y_max) / 1.5;
	set_value(pixel, j, k);
	return (0);
}
