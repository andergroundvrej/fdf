/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:38:58 by ahakobia          #+#    #+#             */
/*   Updated: 2024/10/10 19:57:39 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	key_hooks(t_pixel *pixel)
{
	free_before_exit(pixel);
	exit(-1);
	return (0);
}

int	key_hook(int keycode, t_pixel *pixel)
{
	if (keycode == ESCAPE)
	{
		free_before_exit(pixel);
		exit(-1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_pixel	pixel;

	if (ac != 2)
		return (1);
	if (check_file(av[1]) != 0)
		return (0);
	if (parsing(av[1], &pixel) == 1)
		return (1);
	pixel.mlx = mlx_init();
	if (pixel.mlx == NULL)
		return (1);
	pixel.mlx_win = mlx_new_window(pixel.mlx, 1920, 1080, "fdf");
	if (pixel.mlx_win == NULL)
		return (free_before_exit(&pixel));
	print_window(&pixel);
	mlx_key_hook(pixel.mlx_win, key_hook, &pixel);
	mlx_hook(pixel.mlx_win, 17, 0, key_hooks, &pixel);
	mlx_loop(pixel.mlx);
	return (0);
}
