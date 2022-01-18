/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:21:55 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:42:59 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

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

	c_x_old = (double)x * root ->fitvals.xscale + root ->fitvals.xshift;
	c_y_old = (double)y * root ->fitvals.yscale + root ->fitvals.yshift;
	root ->fitvals.xscale *= zoom;
	root ->fitvals.yscale *= zoom;
	root ->fitvals.xshift *= zoom;
	root ->fitvals.yshift *= zoom;
	root ->fitvals.xshift += calc_new_pos(c_x_old, x,
			root ->fitvals.xshift, root ->fitvals.xscale);
	root ->fitvals.yshift += calc_new_pos(c_y_old, y,
			root ->fitvals.yshift, root ->fitvals.yscale);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_root	*root;

	root = param;
	if (button == 5)
		zoom(x, y, root, 1 / root ->fitvals.zoom);
	if (button == 4)
		zoom(x, y, root, root ->fitvals.zoom);
	if (button == 1)
		root ->fitvals.warp += 0.5;
	if (button == 2)
		root ->fitvals.warp -= 0.5;
	mlx_destroy_image(root ->mlxvars.mlx, root ->pic.image);
	root ->pic.image = mlx_new_image(root ->mlxvars.mlx, XRES, YRES);
	if (root ->pic.image == NULL)
		return (0);
	make_fractal(root);
	return (1);
}

int	key_hook(int keycode, void *param)
{
	t_root	*root;

	root = param;
	if (keycode == 53)
		exit(0);
	keychecks(keycode, root);
	mlx_destroy_image(root ->mlxvars.mlx, root ->pic.image);
	root ->pic.image = mlx_new_image(root ->mlxvars.mlx, XRES, YRES);
	if (root ->pic.image == NULL)
		return (0);
	make_fractal(root);
	return (1);
}
