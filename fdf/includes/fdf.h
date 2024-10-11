/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:02:08 by ahakobia          #+#    #+#             */
/*   Updated: 2024/04/10 14:04:50 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stddef.h>
# include "mlx.h"
# include "get_next_line.h"

# define ESCAPE 65307
# define SQRT2	1.414214
# define WIDTH 	1920
# define HEIGHT 1080

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_line;

typedef struct s_vertex
{
	int	x;
	int	y;
	int	z;
	int	x_p;
	int	y_p;
}	t_vertex;

typedef struct s_pixel
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			temp_x;
	int			temp_y;
	int			x;
	int			y;
	int			x_max;
	int			y_max;
	t_vertex	**map;
}				t_pixel;

void	free_parse(t_pixel *pixel, int y);
int		check_file(char *file);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		free_vertex(t_vertex **str2d, t_pixel *pixel);
int		free_before_exit(t_pixel *pixel);
void	*ft_memset(void *s, int c, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
int		ft_cercle(double x, double y);
void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
int		print_window(t_pixel *pixel);
int		parsing(const char *av, t_pixel *pixel);
size_t	count_words(char const *s, char c);
size_t	word_len(size_t i, char const *s, char c);
void	*total_free(char **str2d);
char	**fill_words(char **str2d, size_t words, char const *s, char c);
char	**ft_split(char const *s, char c);
int		len_fdf(char *str);
long	ft_atol(const char *nptr);
void	bresenham(t_line line, t_pixel *pixel);
int		apply_projection(t_pixel *pixel);

#endif