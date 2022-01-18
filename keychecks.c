/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keychecks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:21:55 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:41:53 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	keychecks(int keycode, t_root *root)
{
	if (keycode == 123)
		root ->fitvals.xshift = root ->fitvals.xshift
			+ -10 * root ->fitvals.xscale;
	if (keycode == 124)
		root ->fitvals.xshift = root ->fitvals.xshift
			+ 10 * root ->fitvals.xscale;
	if (keycode == 125)
		root ->fitvals.yshift = root ->fitvals.yshift
			+ 10 * root ->fitvals.yscale;
	if (keycode == 126)
		root ->fitvals.yshift = root ->fitvals.yshift
			+ -10 * root ->fitvals.yscale;
	if (keycode == 116)
		root ->fitvals.colorshift += 10;
	if (keycode == 121)
		root ->fitvals.colorshift -= 10;
}
