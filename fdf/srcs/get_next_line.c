/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:46:07 by ahakobia          #+#    #+#             */
/*   Updated: 2024/04/07 02:53:39 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_create_line(int fd, char *buffer, char *line);
int		check_buff(char *buff);
int		save_buff(char *buff, char *str);
char	*line_trim(char *str);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*final_line;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	line = ft_create_line(fd, buffer, line);
	if (line == NULL)
		return (NULL);
	save_buff(buffer, line);
	if (*line == 0)
	{
		free(line);
		return (NULL);
	}
	final_line = line_trim(line);
	if (final_line == NULL)
		return (NULL);
	return (final_line);
}

char	*ft_create_line(int fd, char *buffer, char *line)
{
	ssize_t	ret;

	ret = 1;
	if (*buffer != 0)
	{
		line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (NULL);
	}
	while (ret > 0 && check_buff(buffer) != 1)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(line), NULL);
		if (ret == 0)
			break ;
		line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

int	check_buff(char *buff)
{
	if (buff == NULL)
		return (0);
	while (*buff)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

int	save_buff(char *buff, char *str)
{
	size_t	i;

	i = 0;
	if (buff == NULL || str == NULL)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	ft_memset(buff, 0, BUFFER_SIZE);
	if (str[i] == '\n')
	{
		while (str[i])
		{
			i++;
			*buff = str[i];
			buff++;
		}
	}
	return (0);
}

char	*line_trim(char *str)
{
	size_t	len;
	size_t	i;
	char	*final_line;

	final_line = NULL;
	i = 0;
	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
	{
		final_line = malloc(sizeof(char) * (len + 2));
		if (final_line == NULL)
		{
			free(str);
			return (NULL);
		}
		while (i++ != (len))
			final_line[i - 1] = str[i - 1];
		final_line[i - 1] = '\n';
		final_line[i] = '\0';
		free(str);
		return (final_line);
	}
	return (str);
}
