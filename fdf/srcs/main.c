/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:38:58 by ahakobia          #+#    #+#             */
/*   Updated: 2024/03/19 14:36:46 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

// void	init_pixel(t_pixel pixel)
// {
	
// }

int	main(int ac, char *av[])
{
	void	*mlx;
	void	*mlx_win;
	t_pixel	pixel;
	// int		fd;
	// char	*line;
	// int 	i;
	// int 	y;

	// y = 0;
	// i = 0;
	(void)av;
	(void)mlx_win;
	if (ac != 2)
		return (1);
	// fd = open(av[1], O_RDONLY);
	// if (fd == -1)
		// return (-1);
	// line = get_next_line(fd);
	// pixel.x_max = 0;
	// pixel.y_max = 0;
	// pixel.z = 0;
	// while (line)
	// {
	// 	pixel.z = line[0];
	// 	i++;
	// 	if (line[i - 1] == '\n')
	// 	{
	// 		pixel.x_max = i;
	// 		y++;
	// 	}
	// 	line = get_next_line(fd);
	// }
	// printf("%d\n", pixel.x_max);
	// printf("%d\n", pixel.y_max);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
	print_window(mlx, mlx_win, pixel);
	mlx_loop(mlx);
	return (0);
}
