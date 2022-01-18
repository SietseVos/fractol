/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_mod.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:22:37 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:22:38 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	full_mlx_init(t_mlxvars *mlxvars, t_data *pic)
{
	mlxvars ->mlx = mlx_init();
	if (mlxvars ->mlx == NULL)
		return (0);
	mlxvars ->window = mlx_new_window(mlxvars ->mlx, XRES, YRES, "new window");
	if (mlxvars ->window == NULL)
		return (0);
	pic ->image = mlx_new_image(mlxvars ->mlx, XRES, YRES);
	if (pic ->image == NULL)
		return (0);
	return (1);
}

void	fitinit(t_fractfit *fitvals)
{
	fitvals ->zoom = 1.1;
	fitvals ->xscale = 3 / (double)XRES;
	fitvals ->yscale = 2 / (double)YRES;
	fitvals ->xshift = -2;
	fitvals ->yshift = -1;
	fitvals ->warp = (double)2;
	fitvals ->colorshift = 0;
}
