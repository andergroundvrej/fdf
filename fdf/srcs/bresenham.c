/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:27:54 by ahakobia          #+#    #+#             */
/*   Updated: 2024/04/10 07:19:44 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static int	get_sign(int num)
{
	if (num < 0)
		return (-1);
	else if (num > 0)
		return (1);
	return (0);
}

static void	bresenham_smaller(t_line line, t_pixel *pixel)
{
	int	y;
	int	slope;
	int	error;
	int	x;

	x = line.x0;
	y = line.y0;
	slope = 2 * ft_abs(line.y1 - line.y0);
	error = -ft_abs(line.x1 - line.x0);
	while (x != line.x1 + get_sign(line.x1 - line.x0))
	{
		my_mlx_pixel_put(pixel, x, y, 0x0000FFFF);
		error += slope;
		if (error >= 0)
		{
			y += get_sign(line.y1 - line.y0);
			error += -2 * ft_abs(line.x1 - line.x0);
		}
		x += get_sign(line.x1 - line.x0);
	}
}

static void	bresenham_bigger(t_line line, t_pixel *pixel)
{
	int	y;
	int	slope;
	int	error;
	int	x;

	x = line.x0;
	y = line.y0;
	slope = 2 * ft_abs(line.x1 - line.x0);
	error = -ft_abs(line.y1 - line.y0);
	while (y != line.y1 + get_sign(line.y1 - line.y0))
	{
		my_mlx_pixel_put(pixel, x, y, 0x0000FFFF);
		error += slope;
		if (error >= 0)
		{
			x += get_sign(line.x1 - line.x0);
			error += -2 * ft_abs(line.y1 - line.y0);
		}
		y += get_sign(line.y1 - line.y0);
	}
}

void	bresenham(t_line line, t_pixel *pixel)
{
	int	dx;
	int	dy;

	dx = ft_abs(line.x1 - line.x0);
	dy = ft_abs(line.y1 - line.y0);
	if (dy == 0)
	{
		while (line.x0 != line.x1 + get_sign(line.x1 - line.x0))
		{
			my_mlx_pixel_put(pixel, line.x0, line.y0, 0x0000FFFF);
			line.x0 += get_sign(line.x1 - line.x0);
		}
	}
	else if (dx == 0)
	{
		while (line.y0 != line.y1 + get_sign(line.y1 - line.y0))
		{
			my_mlx_pixel_put(pixel, line.x0, line.y0, 0x0000FFFF);
			line.y0 += get_sign(line.y1 - line.y0);
		}
	}
	else if (dx >= dy)
		bresenham_smaller(line, pixel);
	else
		bresenham_bigger(line, pixel);
}
