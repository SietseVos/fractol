/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:23:06 by svos          #+#    #+#                 */
/*   Updated: 2022/01/20 09:09:24 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(double numb, const char *str)
{
	int	factor;

	factor = 10;
	while (*str >= '0' && *str <= '9')
	{
		numb = numb + (((double)(*str - '0')) / factor);
		factor *= 10;
		str++;
	}
	return (numb);
}

double	ft_atoi(const char *str)
{
	int			sign;
	double		numb;

	sign = 1;
	numb = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		numb = (*str - '0') + (numb * 10);
		str++;
	}
	if (*str == '.')
		numb = ft_atod(numb, str + 1);
	return (numb * sign);
}
