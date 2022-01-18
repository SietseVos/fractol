/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svos <svos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 14:21:21 by svos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:47:23 by svos          ########   odam.nl         */
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
	if (ft_memcmp(str, "julia", 6) == 0
		|| ft_memcmp(str, "burning_julia", 14) == 0)
	{
		if (argc < 4)
			return (1);
		root ->fitvals.xjulia = ft_atoi(argv[2]);
		root ->fitvals.yjulia = ft_atoi(argv[3]);
		return (0);
	}
	return (1);
}

int	wrong_input(void)
{
	printf("You input is incorrect.\n\n");
	printf("Use:\n./fractol mandlebrot\n");
	printf("./fractol burning_ship\n");
	printf("./fractol julia [x] [y]\n");
	printf("./fractol burning_julia [x] [y]\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_root		root;
	int			check;

	if (argc < 2 || check_input(argv[1], &root, argc, argv))
		return (wrong_input());
	if (full_mlx_init(&root.mlxvars, &root.pic) == 0)
		return (printf("init failed\n"));
	root.pic.addr = mlx_get_data_addr(root.pic.image, &root.pic.bpp,
			&root.pic.linelen, &root.pic.endian);
	fitinit(&root.fitvals);
	make_fractal(&root);
	check = mlx_hook(root.mlxvars.window, 02, 1L << 0, key_hook, &root);
	if (check == 0)
		return (printf("drawing failed"));
	mlx_hook(root.mlxvars.window, 17, 0L, exit_fractol, 0);
	check = mlx_hook(root.mlxvars.window, 04, 1L << 2, mouse_hook, &root);
	if (check == 0)
		return (printf("drawing failed"));
	mlx_loop(root.mlxvars.mlx);
}
