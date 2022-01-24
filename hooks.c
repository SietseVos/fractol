/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:21:55 by svos          #+#    #+#                 */
/*   Updated: 2022/01/24 09:21:09 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_root	*root;

	root = param;
	if (button == 5)
		zoom(x, y, root, 1 / root ->fractcoords.zoom);
	if (button == 4)
		zoom(x, y, root, root ->fractcoords.zoom);
	if (button == 1)
		root ->fractcoords.warp += 0.5;
	if (button == 2)
		root ->fractcoords.warp -= 0.5;
	return (new_image(root));
}

int	key_hook(int keycode, void *param)
{
	t_root	*root;

	root = param;
	if (keycode == 53)
		exit(0);
	keychecks(keycode, root);
	return (new_image(root));
}
