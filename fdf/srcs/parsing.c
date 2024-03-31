/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrej <andrej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:08:23 by andrej            #+#    #+#             */
/*   Updated: 2024/03/25 17:47:46 by andrej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void parsing(char *av, t_pixel pixel)
{
	int		fd;
	char	*line;

	
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
}
