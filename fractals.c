/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:20:45 by svos          #+#    #+#                 */
/*   Updated: 2022/01/18 13:41:11 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	putcolor(int x, int y, int icount, t_data *pic)
{
	int	color;

	color = 0;
	while (icount > 765)
		icount -= 765;
	while (icount < 0)
		icount += 765;
	if (icount < 255)
		color = icount;
	if (icount >= 255 && icount < 510)
		color = (icount - 254) * 0x00000100;
	if (icount >= 510 && icount < 765)
		color = (icount - 509) * 0x00010000;
	if (icount == 765)
		color = 0x00000000;
	make_pixels(pic, x, y, color);
}

int	pick_fractal(int x, int y, t_fractfit *fitvals, char *fract)
{
	if (ft_memcmp(fract, "mandlebrot", 11) == 0)
		return (mandlebrot_icount(x, y, fitvals));
	if (ft_memcmp(fract, "burning_ship", 13) == 0)
		return (burning_ship_icount(x, y, fitvals));
	if (ft_memcmp(fract, "julia", 6) == 0)
		return (julia_icount(x, y, fitvals));
	if (ft_memcmp(fract, "burning_julia", 14) == 0)
		return (burning_julia_icount(x, y, fitvals));
	return (0);
}

void	make_fractal(t_root *root)
{
	int	x;
	int	y;
	int	icount;

	x = 0;
	while (x < XRES)
	{
		y = 0;
		while (y < YRES)
		{
			icount = pick_fractal(x, y, &root ->fitvals, root ->fractal);
			icount = ((double)icount / (double)MAX_ITER)
				* 765 + root ->fitvals.colorshift;
			putcolor(x, y, icount, &root ->pic);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(root ->mlxvars.mlx,
		root ->mlxvars.window, root ->pic.image, 1, 1);
}
