/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:05:59 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/24 22:14:15 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define LIM 10

int	main(int arc, char **argv)
{
	
	int	fd;
	char *line;
	int	i = 0;

	if (arc != 2) return 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		dprintf(2, "gnl error: %s\n", strerror(errno));
	}
	do {
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		if (line)
			free(line);
		i++;
	} while (line);
	line = get_next_line(-1);
	printf("%s\n", line);
	return (0);
}
