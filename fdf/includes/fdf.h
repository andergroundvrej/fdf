#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stddef.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include <stdlib.h>



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pixel {
	double	x;
	double	y;
	double	**z;
	int		x_max;
	int		y_max;
	double	x_p;
	double	y_p;
}				t_pixel;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
int		ft_cercle(double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    print_window(void *mlx, void *mlx_win, t_pixel pixel);
void	parsing(char *av, t_pixel pixel);
size_t	count_words(char const *s, char c);
size_t	word_len(size_t i, char const *s, char c);
void	*total_free(char **str2d);
char	**fill_words(char **str2d, size_t words, char const *s, char c);
char	**ft_split(char const *s, char c);
int		len_fdf(char *str);

#endif
