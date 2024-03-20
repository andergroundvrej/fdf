/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:02:51 by ahakobia          #+#    #+#             */
/*   Updated: 2024/03/19 06:39:15 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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

	pixel.x = 500;
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, 
			&img.bits_per_pixel, &img.line_length, &img.endian);
	while (pixel.x < 1920)
	{
		pixel.y = 0;
		while (pixel.y < 1080)
		{
			if (ft_cercle(pixel.x, pixel.y) == 1)
				my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x00FFFFFF);
			pixel.y += 0.5;
		}
		pixel.x += 0.5;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}