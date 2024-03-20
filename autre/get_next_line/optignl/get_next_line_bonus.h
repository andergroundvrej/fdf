/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:46:04 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/29 10:20:37 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# define FD_MAX 1024

typedef struct s_buff
{
	char	buff[FD_MAX][BUFFER_SIZE];
	size_t	start;
	size_t	end;
}	t_buff;

char	*get_next_line(int fd);
char	*ft_strjoin_free_s1(char *s1, char *s2, size_t n1, size_t n2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c, size_t n);

#endif
