/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iticount.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:20:45 by svos          #+#    #+#                 */
/*   Updated: 2022/01/24 09:21:57 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	julia_iticount(int x, int y, t_fractcoords *fractcoords)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = fractcoords ->xjulia;
	comnum.cy = fractcoords ->yjulia;
	comnum.zx = fractcoords ->xscale * (double)x + fractcoords ->xshift;
	comnum.zy = fractcoords ->yscale * (double)y + fractcoords ->yshift;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < (double)4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx
			- comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = (double)fractcoords ->warp
			* comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		count++;
	}
	return (count);
}

int	mandlebrot_iticount(int x, int y, t_fractcoords *fractcoords)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = fractcoords ->xscale * (double)x + fractcoords ->xshift;
	comnum.cy = fractcoords ->yscale * (double)y + fractcoords ->yshift;
	comnum.zx = 0;
	comnum.zy = 0;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < (double)4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx
			- comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = (double)fractcoords ->warp
			* comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		count++;
	}
	return (count);
}

int	idunno_iticount(int x, int y, t_fractcoords *fractcoords)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = fractcoords ->xscale * (double)x + fractcoords ->xshift;
	comnum.cy = fractcoords ->yscale * (double)y + fractcoords ->yshift;
	comnum.zx = 0;
	comnum.zy = 0;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < (double)4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx * comnum.zx - 3
			* comnum.zx * comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = ((double)fractcoords ->warp + (double)1) * comnum.zx
			* comnum.zx * comnum.zy - comnum.zy
			* comnum.zy * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		comnum.zy = fabs(comnum.zy);
		comnum.zx = fabs(comnum.zx);
		count++;
	}
	return (count);
}

int	burning_ship_iticount(int x, int y, t_fractcoords *fractcoords)
{
	t_mandlesetcalc	comnum;
	int				count;

	count = 0;
	comnum.cx = fractcoords ->xscale * (double)x + fractcoords ->xshift;
	comnum.cy = fractcoords ->yscale * (double)y + fractcoords ->yshift;
	comnum.zx = 0;
	comnum.zy = 0;
	while ((comnum.zx * comnum.zx + comnum.zy
			* comnum.zy) < (double)4 && count < MAX_ITER)
	{
		comnum.temp = comnum.zx * comnum.zx - comnum.zy * comnum.zy + comnum.cx;
		comnum.zy = (double)fractcoords ->warp
			* comnum.zx * comnum.zy + comnum.cy;
		comnum.zx = comnum.temp;
		comnum.zy = fabs(comnum.zy);
		comnum.zx = fabs(comnum.zx);
		count++;
	}
	return (count);
}
