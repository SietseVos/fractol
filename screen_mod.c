/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_mod.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:22:37 by svos          #+#    #+#                 */
/*   Updated: 2022/01/24 09:19:31 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	full_mlx_setup(t_mlxvars *mlxvars, t_data *pic)
{
	mlxvars ->mlx = mlx_init();
	if (mlxvars ->mlx == NULL)
		return (0);
	mlxvars ->window = mlx_new_window(mlxvars ->mlx,
			XRES, YRES, "fractol window");
	if (mlxvars ->window == NULL)
		return (0);
	pic ->image = mlx_new_image(mlxvars ->mlx, XRES, YRES);
	if (pic ->image == NULL)
		return (0);
	return (1);
}

void	setcoords(t_fractcoords *fractcoords)
{
	fractcoords ->zoom = 1.1;
	fractcoords ->xscale = 3 / (double)XRES;
	fractcoords ->yscale = 2 / (double)YRES;
	fractcoords ->xshift = -2;
	fractcoords ->yshift = -1;
	fractcoords ->warp = (double)2;
	fractcoords ->colorshift = 0;
}
