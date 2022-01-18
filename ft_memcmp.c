/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:22:50 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:22:51 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*f;
	const unsigned char	*d;

	f = s1;
	d = s2;
	while (n > 0)
	{
		if (*f != *d)
			return ((int)(*f - *d));
		n--;
		f++;
		d++;
	}
	return (0);
}
