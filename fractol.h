/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:22:29 by svos          #+#    #+#                 */
/*   Updated: 2022/01/18 13:41:10 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define XRES		1920
# define YRES		1080
# define MAX_ITER	80

typedef struct s_mlxvars
{
	void		*mlx;
	void		*window;
}	t_mlxvars;

typedef struct s_functionals
{
	int	stick;
}	t_fucntionals;

typedef struct s_fractfit
{
	double	zoom;
	double	warp;
	double	xscale;
	double	yscale;
	double	xshift;
	double	yshift;
	int		xjulia;
	int		yjulia;
	int		colorshift;
}	t_fractfit;

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
	t_fractfit		fitvals;
	t_fucntionals	switches;
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

void		make_pixels(t_data *data, int x, int y, int color);
void		fitinit(t_fractfit *fitvals);
void		make_fractal(t_root *root);
void		putcolor(int x, int y, int icount, t_data *pic);
void		putcolor_strange(int x, int y, int icount, t_data *pic);
int			mandlebrot_icount(int x, int y, t_fractfit *fitvals);
int			key_hook(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
int			full_mlx_init(t_mlxvars *mlxvars, t_data *pic);
int			exit_fractol(int param);
double		calcposnew(double c_old, int coord, double shift, double scale);
void		zoom(int x, int y, t_root *root, double zoom);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
int			pick_fractal(int x, int y, t_fractfit *fitvals, char *fract);
int			julia_icount(int x, int y, t_fractfit *fitvals);
int			burning_julia_icount(int x, int y, t_fractfit *fitvals);
int			mandlebrot_icount(int x, int y, t_fractfit *fitvals);
int			burning_ship_icount(int x, int y, t_fractfit *fitvals);
void		keychecks(int keycode, t_root *root);

#endif