/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_pixels.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:22:11 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:22:13 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data ->addr + (y * data ->linelen + x * (data ->bpp / 8));
	*(unsigned int *)dst = color;
}
