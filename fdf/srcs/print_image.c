/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrej <andrej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:02:51 by ahakobia          #+#    #+#             */
/*   Updated: 2024/03/29 01:10:20 by andrej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cercle(double x, double y)
{
	double	carre_x;
	double	carre_y;

	carre_x = (x - 960) * (x - 960);
	carre_y = (y - 540) * (y - 540);
	if (carre_x + carre_y >= 39900 && carre_x + carre_y <= 40100)
		return (1);
	else
		return (0);
		
}

void	print_window(void *mlx, void *mlx_win, t_pixel pixel)
{
	t_data	img;
	int x;
	int y;
	// int j;
	// int i;

	x = 19;
	// i = 0;
	y = 11;
	// j = 800 / 11; 
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, 
			&img.bits_per_pixel, &img.line_length, &img.endian);
	pixel.y = 200;
	while (pixel.y <= 800)
	{
		pixel.x = 400;
		while (pixel.x <= 1600)
		{
			if ((pixel.y >= ((750 / y) + 200) && pixel.y <= ((850 / y) + 200)) && pixel.y <= 800)
				my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x0000FFFF);
			pixel.x += 1;
		}
		if (pixel.y >= ((750 / y) + 200) && pixel.y <= ((850 / y) + 200) && pixel.y <= 800 && y != 0)
			y--;
		pixel.y += 1;
	}
	pixel.x = 400;
	while (pixel.x <= 1600)
	{
		pixel.y = 200;
		while (pixel.y <= 800)
		{
			if ((pixel.x >= ((1550 / x) + 400) && pixel.x <= ((1650 / x) + 400)) && pixel.x <= 1600)
				my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x00FFFF00);
			pixel.y += 1;
		}
		if (pixel.x >= ((1550 / x) + 400) && pixel.x <= ((1650 / x) + 400) && pixel.x <= 1600 && x != 0)
			x--;
		pixel.x += 1;
	}
	// while (pixel.y < 800)
	// {
	// 	pixel.x = 400;
	// 	while (pixel.x < 1600)
	// 	{
	// 		if (pixel.y >= ((j * i) + 150) && pixel.y <= ((j * i) + 250) && pixel.y < 800)
	// 			my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x00FFFFFF);
	// 		pixel.x += 1;
	// 	}
	// 	if (pixel.y >= ((750 / y) + 200) && pixel.y <= ((850 / y) + 200) && pixel.y < 800 && i != 10)
	// 		i++;
	// 	pixel.y += 1;
	// }
	// while (pixel.x < 1920)
	// {
	// 	pixel.y = 0;
	// 	while (pixel.y < 1080)
	// 	{
	// 		if (ft_cercle(pixel.x, pixel.y) == 1)
	// 			my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x00FFFFFF);
	// 		pixel.y += 0.5;
	// 	}
	// 	pixel.x += 0.5;
	// }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
