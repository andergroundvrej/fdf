/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrej <andrej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:38:58 by ahakobia          #+#    #+#             */
/*   Updated: 2024/03/25 22:11:45 by andrej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	void	*mlx;
	void	*mlx_win;
	t_pixel	pixel;

	(void)mlx_win;
	(void)av;
	if (ac != 2)
		return (1);
	// parsing(av[1], pixel);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
	print_window(mlx, mlx_win, pixel);
	mlx_loop(mlx);
	return (0);
}
