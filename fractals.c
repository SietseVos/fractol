/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:20:45 by svos          #+#    #+#                 */
/*   Updated: 2022/01/24 09:23:26 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	putcolor(int x, int y, double iticount, t_data *pic)
{
	int	color;

	while (iticount > 765)
		iticount -= 765;
	while (iticount < 0)
		iticount += 765;
	if (iticount < 255)
		color = iticount;
	if (iticount >= 255 && iticount < 510)
		color = (iticount - 254) * 0x00000100;
	if (iticount >= 510 && iticount < 765)
		color = (iticount - 509) * 0x00010000;
	if (iticount == 765)
		color = 0x00ffffff;
	make_pixels(pic, x, y, color);
}

fptr	pick_fractal(char *fract)
{
	if (ft_memcmp(fract, "mandlebrot", 11) == 0)
		return (&mandlebrot_iticount);
	if (ft_memcmp(fract, "burning_ship", 13) == 0)
		return (&burning_ship_iticount);
	if (ft_memcmp(fract, "julia", 6) == 0)
		return (&julia_iticount);
	if (ft_memcmp(fract, "idunno", 7) == 0)
		return (&idunno_iticount);
	return (0);
}

void	make_fractal(t_root *root)
{
	int		x;
	int		y;
	double	iticount;
	fptr	fractal;

	x = 0;
	fractal = pick_fractal(root ->fractal);
	while (x < XRES)
	{
		y = 0;
		while (y < YRES)
		{
			iticount = fractal(x, y, &root ->fractcoords);
			iticount = ((double)iticount / (double)MAX_ITER)
				* 765 + root ->fractcoords.colorshift;
			putcolor(x, y, iticount, &root ->pic);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(root ->mlxvars.mlx,
		root ->mlxvars.window, root ->pic.image, 1, 1);
}
