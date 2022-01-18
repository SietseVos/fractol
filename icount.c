/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   icount.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:20:45 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:26:34 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	julia_icount(int x, int y, t_fractfit *fitvals)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = (double)fitvals ->xjulia / 100;
	comnum.cy = (double)fitvals ->yjulia / 100;
	comnum.zx = fitvals ->xscale * x + fitvals ->xshift;
	comnum.zy = fitvals ->yscale * y + fitvals ->yshift;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < 4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx - comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = fitvals ->warp * comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		count++;
	}
	return (count);
}

int	burning_julia_icount(int x, int y, t_fractfit *fitvals)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = (double)fitvals ->xjulia / 100;
	comnum.cy = (double)fitvals ->yjulia / 100;
	comnum.zx = fitvals ->xscale * x + fitvals ->xshift;
	comnum.zy = fitvals ->yscale * y + fitvals ->yshift;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < 4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx - comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = fitvals ->warp * comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		comnum.zy = fabs(comnum.zy);
		comnum.zx = fabs(comnum.zx);
		count++;
	}
	return (count);
}

int	mandlebrot_icount(int x, int y, t_fractfit *fitvals)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = fitvals ->xscale * x + fitvals ->xshift;
	comnum.cy = fitvals ->yscale * y + fitvals ->yshift;
	comnum.zx = 0;
	comnum.zy = 0;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < 4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx - comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = fitvals ->warp * comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		count++;
	}
	return (count);
}

int	burning_ship_icount(int x, int y, t_fractfit *fitvals)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = fitvals ->xscale * x + fitvals ->xshift;
	comnum.cy = fitvals ->yscale * y + fitvals ->yshift;
	comnum.zx = 0;
	comnum.zy = 0;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < 4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx - comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = fitvals ->warp * comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		comnum.zy = fabs(comnum.zy);
		comnum.zx = fabs(comnum.zx);
		count++;
	}
	return (count);
}
