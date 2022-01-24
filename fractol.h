/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:22:29 by svos          #+#    #+#                 */
/*   Updated: 2022/01/24 09:16:26 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
#include <unistd.h>

# define XRES		480
# define YRES		270
# define MAX_ITER	600

typedef struct s_mlxvars
{
	void		*mlx;
	void		*window;
}	t_mlxvars;

typedef struct s_fractcoords
{
	double	zoom;
	float	warp;
	double	xscale;
	double	yscale;
	double	xshift;
	double	yshift;
	float	xjulia;
	float	yjulia;
	int		colorshift;
}	t_fractcoords;

typedef struct s_data
{
	void	*image;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_data;

typedef struct s_root
{
	t_mlxvars		mlxvars;
	t_data			pic;
	t_fractcoords	fractcoords;
	char			*fractal;
}	t_root;

typedef struct s_mandlesetcalc
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	temp;
}	t_mandlesetcalc;

typedef int (*fptr) (int, int, t_fractcoords*);

void		make_pixels(t_data *data, int x, int y, int color);
void		setcoords(t_fractcoords *fractcoords);
void		make_fractal(t_root *root);
int			mandlebrot_iticount(int x, int y, t_fractcoords *fractcoords);
int			key_hook(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
int			full_mlx_setup(t_mlxvars *mlxvars, t_data *pic);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
double		ft_atoi(const char *str);
int			julia_iticount(int x, int y, t_fractcoords *fractcoords);
int			mandlebrot_iticount(int x, int y, t_fractcoords *fractcoords);
int			burning_ship_iticount(int x, int y, t_fractcoords *fractcoords);
int			idunno_iticount(int x, int y, t_fractcoords *fractcoords);
int			exit_fractol(int param);
void		keychecks(int keycode, t_root *root);
int			new_image(t_root *root);
void		zoom(int x, int y, t_root *root, double zoom);
double		calc_new_pos(double c_old, int coord, double shift, double scale);

#endif