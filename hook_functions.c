/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:21:55 by svos          #+#    #+#                 */
/*   Updated: 2022/01/26 15:45:56 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	keychecks(int keycode, t_root *root)
{
	if (keycode == 123)
		root ->fractcoords.xshift = root ->fractcoords.xshift
			+ -10 * root ->fractcoords.xscale;
	if (keycode == 124)
		root ->fractcoords.xshift = root ->fractcoords.xshift
			+ 10 * root ->fractcoords.xscale;
	if (keycode == 125)
		root ->fractcoords.yshift = root ->fractcoords.yshift
			+ 10 * root ->fractcoords.yscale;
	if (keycode == 126)
		root ->fractcoords.yshift = root ->fractcoords.yshift
			+ -10 * root ->fractcoords.yscale;
	if (keycode == 116)
		root ->fractcoords.colorshift += 10;
	if (keycode == 121)
		root ->fractcoords.colorshift -= 10;
}

int	exit_fractol(int param)
{
	exit(param);
	return (0);
}

double	calc_new_pos(double c_old, int coord, double shift, double scale)
{
	double	dif;
	double	c_new;

	c_new = coord * scale + shift;
	dif = c_old - c_new;
	return (dif);
}

void	zoom(int x, int y, t_root *root, double zoom)
{
	double	c_x_old;
	double	c_y_old;

	c_x_old = (double)x * root ->fractcoords.xscale + root ->fractcoords.xshift;
	c_y_old = (double)y * root ->fractcoords.yscale + root ->fractcoords.yshift;
	root ->fractcoords.xscale *= zoom;
	root ->fractcoords.yscale *= zoom;
	root ->fractcoords.xshift *= zoom;
	root ->fractcoords.yshift *= zoom;
	root ->fractcoords.xshift += calc_new_pos(c_x_old, x,
			root ->fractcoords.xshift, root ->fractcoords.xscale);
	root ->fractcoords.yshift += calc_new_pos(c_y_old, y,
			root ->fractcoords.yshift, root ->fractcoords.yscale);
}

int	new_image(t_root *root)
{
	mlx_destroy_image(root ->mlxvars.mlx, root ->pic.image);
	root ->pic.image = mlx_new_image(root ->mlxvars.mlx, XRES, YRES);
	if (root ->pic.image == NULL)
		return (0);
	make_fractal(root);
	return (1);
}
