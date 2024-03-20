/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:47:12 by ccouble           #+#    #+#             */
/*   Updated: 2023/11/29 09:29:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("./bible.txt", O_RDONLY);
	int i = 0;
	char *line;
	do
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	} while (line != NULL);
}
