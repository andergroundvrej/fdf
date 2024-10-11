/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:02:51 by ahakobia          #+#    #+#             */
/*   Updated: 2024/04/10 07:56:26 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_horizontal(t_pixel *pixel, int y, int x)
{
	t_line	line;

	line.x0 = pixel->map[y][x].x_p;
	line.y0 = pixel->map[y][x].y_p;
	line.x1 = pixel->map[y][x + 1].x_p;
	line.y1 = pixel->map[y][x + 1].y_p;
	bresenham(line, pixel);
}

void	draw_line_vertical(t_pixel *pixel, int y, int x)
{
	t_line	line;

	line.x0 = pixel->map[y][x].x_p;
	line.y0 = pixel->map[y][x].y_p;
	line.x1 = pixel->map[y + 1][x].x_p;
	line.y1 = pixel->map[y + 1][x].y_p;
	bresenham(line, pixel);
}

void	draw(t_pixel *pixel)
{
	int	x;
	int	y;

	y = 0;
	while (y < pixel->y_max)
	{
		x = 0;
		while (x < pixel->x_max - 1)
		{
			draw_line_horizontal(pixel, y, x);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < pixel->y_max - 1)
	{
		x = 0;
		while (x < pixel->x_max)
		{
			draw_line_vertical(pixel, y, x);
			x++;
		}
		y++;
	}
}

int	print_window(t_pixel *pixel)
{
	pixel->img = mlx_new_image(pixel->mlx, 1920, 1080);
	if (pixel->img == NULL)
		return (free_before_exit(pixel));
	pixel->addr = mlx_get_data_addr(pixel->img,
			&pixel->bits_per_pixel, &pixel->line_length, &pixel->endian);
	if (pixel->addr == NULL)
		return (free_before_exit(pixel));
	apply_projection(pixel);
	draw(pixel);
	mlx_put_image_to_window(pixel->mlx, pixel->mlx_win, pixel->img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = pixel->addr + (y * pixel->line_length
			+ x * (pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
