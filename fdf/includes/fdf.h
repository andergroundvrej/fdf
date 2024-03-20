#ifndef FDF_H
# define FDF_H

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
	double	z;
	int		x_max;
	int		y_max;
	double	x_p;
	double	y_p;
}				t_pixel;

int	ft_cercle(double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    print_window(void *mlx, void *mlx_win, t_pixel pixel);

#endif