/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:21:21 by svos          #+#    #+#                 */
/*   Updated: 2022/01/21 11:21:48 by svos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	check_input(char *str, t_root *root, int argc, char **argv)
{
	root ->fractal = str;
	if (ft_memcmp(str, "mandlebrot", 11) == 0)
		return (0);
	if (ft_memcmp(str, "burning_ship", 13) == 0)
		return (0);
	if (ft_memcmp(str, "julia", 6) == 0)
	{
		if (argc < 4)
			return (1);
		root ->fractcoords.xjulia = ft_atoi(argv[2]);
		root ->fractcoords.yjulia = ft_atoi(argv[3]);
		return (0);
	}
	if (ft_memcmp(str, "idunno", 7) == 0)
		return (0);
	return (1);
}

int	wrong_input_messege(void)
{
	write(1, "Your input is incorrect.\n\n", 26);
	write(1, "Use:\n./fractol mandlebrot\n", 27);
	write(1, "./fractol burning_ship\n", 23);
	write(1, "./fractol julia [x] [y]\n", 24);
	write(1, "./fractol idunno\n", 17);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root		root;
	int			check;

	if (argc < 2 || check_input(argv[1], &root, argc, argv))
		return (wrong_input_messege());
	if (full_mlx_setup(&root.mlxvars, &root.pic) == 0)
		return (write(1, "init failed\n", 12));
	root.pic.addr = mlx_get_data_addr(root.pic.image, &root.pic.bpp,
			&root.pic.linelen, &root.pic.endian);
	setcoords(&root.fractcoords);
	make_fractal(&root);
	check = mlx_hook(root.mlxvars.window, 02, 1L << 0, key_hook, &root);
	if (check == 0)
		return (write(1, "drawing failed\n", 15));
	check = mlx_hook(root.mlxvars.window, 17, 0L, exit_fractol, 0);
	if (check == 0)
		return (write(1, "drawing failed\n", 15));
	check = mlx_hook(root.mlxvars.window, 04, 1L << 2, mouse_hook, &root);
	if (check == 0)
		return (write(1, "drawing failed\n", 15));
	mlx_loop(root.mlxvars.mlx);
}
